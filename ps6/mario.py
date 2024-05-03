# Print a pyramid like mario
while True:
    try:
        height = int(input("Height: "))
        if height <= 8 and height >= 1:
            break
        else:
            print("Enter a positive integer between 1 and 8")
    except ValueError:
        print("Not an integer")


for i in range(height):
    print(" " * (height - i -1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1))
