from flask import Flask, render_template, request

# Underscore underscore name underscore underscore refers to the current file,
# and so this is just a little trick that says, turn this file into a Flask application
app = Flask(__name__)
