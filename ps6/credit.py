import cs50
import re

def main():
    # Get the number and make sure it's entirely numeric
    number = cs50.get_int("Number: ")
    # Convert number from int to str for checking
    str_number = str(number)

    if is_desired_length(str_number, 15):
        if is_VISA(str_number):
            print("VISA")
            return 0
    elif is_desired_length(str_number, 13):
        if is_AMEX(str_number):
            print("AMEX")
            return 0
    elif is_desired_length(str_number, 16):
        if is_VISA(str_number):
            print("VISA")
            return 0
        elif is_MASTERCARD:
            print("MASTERCARD")
            return 0

    print("INVALID\n")
    return 0


# Use regular expression opreation to check number's length
def is_desired_length(str_number, desired_length):
    # Define the regular expression pattern
    pattern = r'^\d{' + str(desired_length) + r'}$'

    # Check if input matches the pattern
    if re.match(pattern, str_number):
        return True
    else:
        return False


# Use Luhn's Algorithm to check the
def algorithm(str_number):
    for i in 


def is_VISA(str_number):



def is_AMEX(str_number):
    .


def is_MASTERCARD(str_number):
    .



main()
