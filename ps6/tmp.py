# TODO
from cs50 import get_int


def main():
    card_number = card_detail()
    validate = check_valid(card_number)
    card_type(card_number, validate)

# prompt user for input and valid


def card_detail():
    while True:
        card_number = input("Card Number: ")
        if card_number.isnumeric():
            break

    return card_number

# check if entry is valid and divisible
# verify odd multiples if more than 10 add together


def check_valid(card_number):
    even_num = 0
    odd_num = 0
    card_number = reversed([int(digit) for digit in card_number])
    for i, digit in enumerate(card_number):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                odd_num += int(odd_digit / 10) + odd_digit % 10
            else:
                odd_num += odd_digit
        else:
            even_num += digit
    validate = even_num + odd_num
    return validate

# check card type by numbers entered and number length
# amex starting with 34 or 37
# mastercard starting 51- 55
# visa starting with 4 length 13 or 16


def card_type(card_number, validate):
    first_number = int(card_number[0:2])
    card_length = len(card_number)
    validate_last_digit = validate % 10

    if validate_last_digit == 0:
        if first_number in [34, 37] and card_length == 15:
            print("AMEX")
        elif (int(card_number[0]) == 4) and card_length in [13, 16]:
            print("VISA")
        elif (first_number in range(51, 55)) and card_length == 16:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
