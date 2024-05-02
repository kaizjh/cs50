# It turns out that there is no need to code main function in every source file in python
# And if you do code a main function in python, don't forget to call it
# And usually we call the main() in the bottom of the file, so that we can use other functions defined after main(), but used by main()

def main():
    for i in range(3):
        meow()


def meow():
    print("meow")


main()
