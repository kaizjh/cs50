# Noticed that, there are double blank lines between functions, is just a conventional style
def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    # There is no "do ... while...(in c)" loop in python, but there is a way to do the same thing
    # That is using a infinite loop:
    while True:
        n = int(input("Height: "))
        if n > 0:
            break
    # Break the while loop then return n, that means the scope problem in c does not exist in python
    # And if we return in the while loop is also right
    return n


main()
