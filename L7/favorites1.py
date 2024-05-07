import cs50

db = cs50.SQL("sqlite:///favorites.db")

favorite = cs50.get_string("Favorites: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = '{favorite}'")

print(rows[0])
