import datetime
import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Disable caching of responses, lest you make a change to some file but your browser not notice. --Irving
@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get the user's id and name from session who is logged in currently
    user_id = session["user_id"]
    # Only get the str username, not a list or a dict
    username = db.execute("SELECT username FROM users WHERE id = ?", user_id)[0]["username"]

    # Get the user's stocks'symbol and shares from datebase
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM buy WHERE user_id = ? GROUP BY symbol", user_id)

    # If the user hasn't bought stocks, apology
    if not stocks:
        return apology("you haven't bought any stocks,let's go quote and buy!")

    # If bought, display the information
    else:
        # Look up for the current price according to the stock's symobl, then add a '$' sign, then add price into the stocks
        for stock in stocks:
            stock["price"] = lookup(stock["symbol"])["price"]
            stock["value"] = stock["price"] * stock["total_shares"]

            # Store the usds in a sigle column
            stock["usd_value"] = usd(stock["value"])
            stock["usd_price"] = usd(stock["price"])

        # Get the user's remaining cash from TABLE buy
        cash = db.execute("SELECT cash FROM buy WHERE user_id = ? ORDER BY time DESC LIMIT 1", user_id)[0]["cash"]

        # Calculate the total
        total = cash
        for stock in stocks:
            print(total, stock["value"])
            total = total + stock["value"]

        return render_template("index.html", stocks=stocks, username=username, cash=usd(cash), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))

        # Check the validation
        if not symbol or shares <= 0:
            return apology("invalid symbol or/and number of shares")
        else:

            # Using lookup function to get the stock's price, if it returns None, the stock of this symbol does not exists
            stock = lookup(symbol)
            if not stock:
                return apology("this symbol does not exists")

            # Get the user_id from session remembered by login()
            user_id = session["user_id"]

            # Get the total price of stocks, and the cashs of this account
            total = stock["price"] * shares
            cashs = db.execute("SELECT cash FROM buy WHERE user_id = ?", user_id)

            # If it is the first transaction, get the default money, if not, get the minimum cash of the list cashs
            if not cashs:
                cash = 10000
            else:
                cash_list = [row['cash'] for row in cashs]
                cash = min(cash_list)

            # If this account does not have so much money, then apology
            if total > cash:
                return apology("Your account balance is insufficient for this transaction")
            else:
                # Record the transaction
                former = cash
                cash = cash - total
                time = datetime.datetime.now()
                price = stock["price"]
                db.execute("INSERT INTO buy(user_id, symbol, price, shares, cash, time) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, price, shares, cash, time)
                return render_template("bought.html", symbol=symbol, shares=shares, price=usd(price), cash=usd(cash), total=usd(total), former=usd(former))

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("invalid symbol")
        else:
            stock = lookup(symbol)

            # Check if symbol exists
            if not stock:
                return apology("this symbol does not exists")

            return render_template("quoted.html", price=usd(stock["price"]), symbol=stock["symbol"])



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "GET":
        return render_template("register.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Check username and password
        if not username or not password or not confirmation:
            return apology("invalid username or/and invalid password")
        elif password != confirmation:
            return apology("you passwords do not match")

        # Check if the username exists
        username_exists = db.execute("SELECT * FROM users WHERE username = ?", username)
        if username_exists:
            return apology("username already exists")

        # Hash the password and insert the new user into the database
        hash = generate_password_hash(password)
        db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", username, hash )
        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Get the user's id from session
    user_id = session["user_id"]

    if request.method == "GET":

        # Get the user's stocks'symbol and shares from datebase
        stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM buy WHERE user_id = ? GROUP BY symbol", user_id)

        # If the user hasn't bought stocks, apology
        if not stocks:
            return apology("you have nothing to sell,let's go quote and buy!")
        else:
            return render_template("sell.html", stocks=stocks)

    # If "POST"
    else:
        # Get arguments from sell.html
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Check if the shares is a positive number
        if not shares.isnumeric() or int(shares) <= 0:
            return apology("invalid shares")

        # Check if the user owned this the symbol of stock and if the user's shares is enough
        owned = db.execute("SELECT SUM(shares) as total_shares, price FROM buy WHERE symbol = ? AND user_id = ?",symbol, user_id)[0]
        print(owned)
        if not owned:
            return apology("you haven't bought this stock or invalid symbol")
        elif owned["total_shares"] < int(shares):
            return apology("you haven't bought enough shares of this stock")

        price = owned["price"]
        cash = db.execute("SELECT cash FROM buy WHERE user_id = ? ORDER BY time DESC LIMIT 1", user_id)[0]["cash"]
        cash = cash - shares * price
        db.execute("INSERT INTO buy(user_id, symbol, price, shares, cash, time) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, price, -shares, cash, time)
        return redirect("/")


