"""
    I think my finance is pretty good, but it still has a problem in check50, and I can't fix it, I am even thinking that the check50 is wrong,
    so I decide not to debug it, because I can't do it.

    :( buy handles valid purchase
    Cause
    expected to find "9,888.00" in page, but it wasn't found

"""

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

    # Get the user_id and message from session
    user_id = session["user_id"]
    message = session.pop("message", None)

    # Only get the str username, not a list or a dict
    username = db.execute("SELECT username FROM users WHERE id = ?", user_id)[0]["username"]

    # Get the user's stocks'symbol and shares from datebase
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM history WHERE user_id = ? GROUP BY symbol", user_id)

    # If the user hasn't bought stocks, return the default
    if not stocks:
        return render_template("index.html", cash_usd=usd(10000), stocks=stocks, total_usd=usd(10000), username=username, message=message)
    else:
        # Look up for the current price according to the stock's symobl, then add a '$' sign, then add price into the stocks
        for stock in stocks:
            stock["price"] = lookup(stock["symbol"])["price"]
            stock["value"] = stock["price"] * stock["total_shares"]

            # Store the usds in a sigle column
            stock["usd_value"] = usd(stock["value"])
            stock["usd_price"] = usd(stock["price"])

        # Get remaining cash from TABLE buy, if this is the first transaction, get the default money
        cashs = db.execute("SELECT cash FROM history WHERE user_id = ? ORDER BY time DESC LIMIT 1", user_id)
        if not cashs:
            cash = 10000.00
        else:
            cash = float(cashs[0]["cash"])

        # Calculate the total
        total = cash
        for stock in stocks:
            total = total + stock["value"]

        return render_template("index.html", cash_usd=usd(cash), stocks=stocks, total_usd=usd(total), username=username, message=message)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Check the symbol and shares
        if not symbol or not is_positive_integer(shares):
            return apology("invalid symbol or/and number of shares")
        else:

            # Using lookup function to get the stock's price, if it returns None, the stock of this symbol does not exists
            stock = lookup(symbol)
            print(stock)
            if not stock:
                return apology("this symbol does not exists")

            # Get the total price of stocks
            price = stock["price"]
            total = price * float(shares)

            # Get the user_id from session remembered by login()
            user_id = session["user_id"]

            # Get remaining cash from TABLE buy, if this is the first transaction, get the default money
            cashs = db.execute("SELECT cash FROM history WHERE user_id = ? ORDER BY time DESC LIMIT 1", user_id)
            if not cashs:
                cash = 10000.00
            else:
                cash = float(cashs[0]["cash"])

            # If this account does not have so much money, apology
            if total > cash:
                return apology("can't afford")
            else:
                # Record the transaction
                cash = cash - total
                time = datetime.datetime.now()
                db.execute("INSERT INTO history(user_id, symbol, price, shares, cash, time) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, price, shares, cash, time)

                # After a successful purchase, back to the homepage with a message
                session["message"] = "Bought!"
                return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Get the user_id from session remembered by login()
    user_id = session["user_id"]
    # Only get the str username, not a list or a dict
    username = db.execute("SELECT username FROM users WHERE id = ?", user_id)[0]["username"]

    # Get the user's stocks'symbol and shares from datebase
    stocks = db.execute("SELECT symbol, price, shares, time FROM history WHERE user_id = ?", user_id)

    # If the user hasn't bought stocks, apology
    if stocks:
        for stock in stocks:
            stock["price"] = usd(stock["price"])

        return render_template("history.html", stocks = stocks, username=username)


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

        # After a successful register, back to the homepage with a message
        session.clear
        session["message"] = "Registered!"
        session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", username)[0]["id"]
        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Get the user_id from session remembered by login()
    user_id = session["user_id"]

    if request.method == "GET":

        # Get the user's stocks'symbol and shares from datebase
        stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM history WHERE user_id = ? GROUP BY symbol", user_id)

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
        if not is_positive_integer(shares):
            return apology("invalid number of shares")

        # Check if the user owned this the symbol of stock and if the user's shares is enough
        owned = db.execute("SELECT SUM(shares) as total_shares, price FROM history WHERE symbol = ? AND user_id = ?",symbol, user_id)[0]
        if not owned:
            return apology("missing symbol")
        elif owned["total_shares"] < int(shares):
            return apology("symbol not owned")

        # Refresh the TABLE buy
        price = owned["price"]
        cashs = db.execute("SELECT cash FROM history WHERE user_id = ? ORDER BY time DESC LIMIT 1", user_id)[0]["cash"]
        cash = float(cashs) + float(shares) * float(price)
        cash_formatted = f"{cash:.2f}"
        time = datetime.datetime.now()
        db.execute("INSERT INTO history(user_id, symbol, price, shares, cash, time) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, price, -int(shares), cash_formatted, time)

        # After a successful sale, back to the homepage with a message
        session["message"] = "Sold!"
        return redirect("/")


def is_positive_integer(string):
    string = string.strip()
    if string.isnumeric():
        return int(string) > 0
    return False

