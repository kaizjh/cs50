from sys import argv

# Using slices of lists, I can skip the first argument, and "1: " means: 1 to the end
for arg in argv[1:]:
    print(arg)

# Or just print the second argument
for arg in argv[1:2]:
    print("@",arg)
