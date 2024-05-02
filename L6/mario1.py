# Get more details about print() from https://docs.python.org/3/library/functions.html#print
print("#" * 3)


# These 3 lines below, doing the same thing as 1 line above, and this is the powerful of python
for i in range(3):
    print("#", end="")
print()


print()


for i in range(3):
    print("#" * 3)


print()


for i in range(3):
    for j in range(3):
        print("#", end='')
    print()
