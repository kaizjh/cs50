import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

name = input("Name: ")

if name in names:
    print("Founded")
    sys.exit(0)

for n in names:
    if name == n:
        print("Founded")
        sys.exit(0)


print("Not found")
sys.exit(1)
