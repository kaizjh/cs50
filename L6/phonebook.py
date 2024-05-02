# This is similar to scores.py "scores = []"
# This actually the shorthand version of this: people = dict(), which means create a empty dictionary
people = {
    "Irving": "1243255",
    "David": "+1-845-436-3422"
}

# Dictionary is just so wonderfully
name = input("Name: ")
if name in people:
    print(f"Number: {people[name]}")


