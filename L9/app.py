from flask import Flask, render_template, request

# Underscore underscore name underscore underscore refers to the current file,
# and so this is just a little trick that says, turn this file into a Flask application
app = Flask(__name__)

# This is known as a decorator in Python, not a flask feature
@app.route("/")
def index():
    name = request.args.get("name", "world")

    return render_template("index.html", name=name)
