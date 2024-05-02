import csv

# This with line is the pythonic way, this is jsut a matter of saying:
# with the following opening of the file, do these next four lines of code,
# and then automatically close it for me at the end of the indentation.
with open("phonebook.csv", "a") as file:

    name = input("name:")
    number = input("number:")

    writer = csv.writer(file)
    writer.writerow([name, number])
