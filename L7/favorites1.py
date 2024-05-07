import cs50

db = cs50.SQL("sqlite:///favorites.db")

favorite = cs50.get_string("Favorites: ")

# The '?' inside the "" is a placeholder, just like %S in C
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
# The code below would do the same thing as a Python way, but you will expose yourself to potential hack or attacks by trusting the user's input, so don't do this
# rows = db.execute(f"SELECT COUNT(*) AS n FROM favorites WHERE problem = '{favorite}'")

# For example, if there is a code for account log in:
# rows = db.execute(f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
# and when I typed in the username literally as:    malan@harvard.edu'--    , and no password, and the execute code will become:
# rows = db.execute(f"SELECT * FROM users WHERE username = 'malan@harvard.edu'--' AND password = '{password}'")
# and because -- means there is a comment comes in the right, then it becomes:
# rows = db.execute(f"SELECT * FROM users WHERE username = 'malan@harvard.edu'")
# that means I skip the password, and heck in the malan@harvard.edu's accout, without his password, that is horrible

for row in rows:
    print(row['n'])

# We can print this one, too, because there is only one row
print(rows[0]['n'])
