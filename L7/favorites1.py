import cs50

db = cs50.SQL("sqlite:///favorites.db")

favorite = cs50.get_string("Favorites: ")

rows = db.execute(f"SELECT COUNT(*) AS n FROM favorites WHERE problem = '{favorite}'")

for row in rows:
    print(row['n'])

# We can print this one, too, because there is only one row
print(rows[0]['n'])
