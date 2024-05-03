# Print a pyramid like mario
while True:
    try:
        height = input("Height: ")
    except ValueError:
        print("Not an integer")


for i in range(height):
    print(" " * (height - i -1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1), end="")
    print(" " * (height - i - 1))

