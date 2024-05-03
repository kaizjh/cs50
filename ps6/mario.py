

while True:
    height = int(input("Height: "))
    if height <= 8 and height >= 1:
        break

for i in range(height):
    print(" " * (height - i -1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1), end="")
    print(" " * (height - i - 1))

