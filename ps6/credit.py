import re

def main():
    # Get the number and make sure it's entirely numeric
    while(True):
        str_number = input("Number: ")
        if str_number.isnumeric():
            break

    # Check the number and print the result
    if (is_desired_length(str_number, 13) or is_desired_length(str_number, 16)) and is_VISA(str_number):
        print("VISA")
    elif is_desired_length(str_number, 15) and is_AMEX(str_number):
        print("AMEX")
    elif is_desired_length(str_number, 16) and is_MASTERCARD(str_number):
        print("MASTERCARD")
    else:
        print("INVALID")

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


def is_VISA(str_number):
    if str_number[0] == '4':
        if card_is_valid(str_number):
            return True
    return False


def is_AMEX(str_number):
    if str_number[0] == '3' and (str_number[1] == '4' or str_number[1] == '7'):
        if card_is_valid(str_number):
            return True
    return False


def is_MASTERCARD(str_number):
    if str_number[0] == '5' and str_number[1] >= '1' and str_number[1] <= '5':
        if card_is_valid(str_number):
            return True
    return False


# Use Luhn's Algorithm to check the credit's validation
def card_is_valid(str_number):
    # Convert the card number string to a list of integers
    digits = [int(x) for x in str_number]
    # Double every other digit starting from the second-to-last digit
    for i in range(len(digits) - 2, -1, -2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9

    # Sum all the digits
    total_sum = sum(digits)
    # Final check
    if total_sum % 10 == 0:
        return True
    else:
        return False
    

main()
