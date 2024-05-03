import csv

books = []

with open ("books.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)
