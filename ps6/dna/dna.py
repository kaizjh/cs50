import csv
import sys


def main():

    # TODO: Check for command-line usage
    n = len(sys.argv)
    if n != 3:
        print("Usage:python dna.py filename.csv filename.txt")

    # TODO: Read database file into a variable
    with open (sys.argv[1]) as file:
        # Use reader to store csv file in dict
        reader = csv.DictReader(file)
        # Get the csv fieldnames into list STRs
        STRs = reader.fieldnames
        # Append dicts into list rows, expect the fieldname
        rows = []
        for read in list(reader)[1:]:
            rows.append(read)

    # TODO: Read DNA sequence file into a variable
    with open (sys.argv[2]) as file:
        text = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Get every STR's longest_match in DNA sequence file, store them into list numbers
    numbers = []
    for STR in STRs:
        print(longest_match(text, STR))
        numbers.append(longest_match(text, STR))

    # TODO: Check database for matching profiles
    n = len(STRs)
    print(n)
    for row in rows:
        matched = True
        for i in range(1,n):
            print(numbers[i], row.get(STRs[i]))
            if numbers[i] != row.get(STRs[i]):
                matched = False
                break

        if matched:
            print(row.get(STRs[0]))
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
