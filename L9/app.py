from flask import Flask, render_template, request

# Underscore underscore name underscore underscore refers to the current file,
# and so this is just a little trick that says, turn this file into a Flask application
app = Flask(__name__)

# This is known as a decorator in Python, not a flask feature
@app.route("/")

def index():
    return render_template("index.html")

# The default methods=["GET"]
@app.route("/greet", methods=["POST"])
def greet():
    # request.args.get() is a method inside the object request.args, and the  "world" is the default value of the function
    return render_template("greet.html", name=request.args.get("name", "world"))
