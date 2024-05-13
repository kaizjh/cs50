from flask import Flask, render_template, request

# Underscore underscore name underscore underscore refers to the current file,
# and so this is just a little trick that says, turn this file into a Flask application
app = Flask(__name__)

# This is known as a decorator in Python, not a flask feature
@app.route("/", methods=["GET", "POST"])

def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))


