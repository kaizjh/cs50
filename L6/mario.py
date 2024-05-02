# There is no "do ... while...(in c)" loop in python, but there is a way to do the same thing
# That is using a infinite loop:
while True:
    n = int(input("Height: "))
    if n > 0:
        break

for i in range(n):
    print("#")

