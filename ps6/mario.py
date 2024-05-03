

while True:
    height = int(input("Height: "))
    if height <= 8 and height >= 1:
        break

for i in range(height):
    print(" " * (height - i), end="")
    print("#" * i, end="  ")
    print("#" * i, end="")
    print(" " * (height - i))

