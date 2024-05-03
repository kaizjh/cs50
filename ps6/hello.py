from sys import argv

n = len(argv)

if n < 2:
    print("Hello, world!")
elif n == 2:
    print(f"Hello, {argv[1]}")
else:
    print("Hello, ", end="")
    for arg in argv[1:]:
        print(f"{arg} ", end="")
    print()
