# Print a pyramid like mario
while True:
    try:
        height = input("Height: ")
    except ValueError:
        print("Not an integer")
        continue

    if height <= 8 and height >= 1:
        break
    else:
        print("Enter a positive integer between 1 and 8")

for i in range(height):
    print(" " * (height - i -1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1), end="")
    print(" " * (height - i - 1))

