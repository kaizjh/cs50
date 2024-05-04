import cs50
import re

def main:
    # Get the number and make sure it's entirely numeric
    number = cs50.get_int("Number: ")
    print(number)
    


# Use regular expression opreation to check number's length
def valid_credit:
    string = str(number)
    pattern = r'^\d{' + str

