import cs50
import re

def main():
    # Get the number and make sure it's entirely numeric
    number = cs50.get_int("Number: ")
    print(number)

    if is_desired_length(number, 15):
        if is_VISA(number):
            print("VISA")
            return 0
    elif is_desired_length(number, 13):
        if is_AMEX(number):
            print("AMEX")
            return 0
    elif is_desired_length(number, 16):
        if is_VISA(number):
            print("VISA")
            return 0
        elif is_MASTERCARD:
            print("MASTERCARD")
            return 0

    print("INVALID\n")
    return 0


# Use regular expression opreation to check number's length
def is_desired_length(number, desired_length):
    # Define the regular expression pattern
    pattern = r'^\d{' + str(desired_length) + r'}$'

    # Check if input matches the pattern
    if re.match(pattern, str(number)):
        return True
    else:
        return False


def is_VISA(number):
    


def is_AMEX(number):
    .


def is_MASTERCARD(number):
    .


main()
