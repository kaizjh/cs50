import csv

#Use csv.reader returns a list[]
with open("favorites.csv", "r") as file:
    reader = csv.reader(file)

    for row in reader:
        favorite = row[1]
        print(favorite, end='  ')


print("----------------------------")
# Use csv.DictReader returns a dict{}
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        favorite = row["language"]
        print(favorite, end='  ')


print("---------------------------------")
# Down here is a more dynamic version, and count the favorites
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {}
    for row in reader:
        if favorite in counts:
            counts[favorite] += 1
        else:
            # Whenever we see a new language, we create a new item
            counts[favorite] = 1
