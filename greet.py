from sys import argv

# Using slices of lists, I can skip the first argument
for arg in argv[1:]:
    print(arg)

# Or just print the second argument
for arg in argv[1:2]:
    print("@",arg)
