import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)

    for row in reader:
        favorite = row[1]
        print(favorite, end='  ')

print("----------------------------")

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        favorite = row["language"]
        print(favorite, end='  ')
