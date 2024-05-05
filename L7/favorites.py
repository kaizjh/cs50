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
        favorite = row["language"]
        if favorite in counts:
            # Use the item's key to access the value in the dict, increase the value
            counts[favorite] += 1
        else:
            # Whenever we see a new language, we create a new item(technical term), and initialize it
            counts[favorite] = 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

# Get the print results sorted by keys' alphbets
for favorite in sorted(counts):
    print(f"{favorite}: {counts[favorite]}")

print("_________________________________")
# Sorted by value(actually use values to substitute keys), and print
def get_value(language):
    return counts[language]

for favorite in sorted(counts, key=get_value, reverse = True):
    print(f"{favorite}: {counts[favorite]}")

print("__________________________________")
# Sorted by value, but in a fancy way
for favorite in sorted(counts, key=lambda language: counts[language], reverse = True):
    print(f"{favorite}: {counts[favorite]}")
