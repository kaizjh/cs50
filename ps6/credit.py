import cs50
import re

def main:
    # Get the number and make sure it's entirely numeric
    number = cs50.get_int("Number: ")
    print(number)
    valid_credit



# Use regular expression opreation to check number's length
def valid_credit(number, length):
    # Define the regular expression pattern
    pattern = r'^\d{' + str(length) + r'}$'

    # Check if input matches the pattern
    if re.match(pattern, str(number)):
        return True
    else:
        return False

