def main():
    text = []
    text = input("Text: ")

    texts = text.lower()
    print(texts)

    words = 1
    letters = 0
    for c in texts:
        # Count the words
        if c == ' ':
            words += 1
        # Count the letters
        if c >='a' and c <= 'z':
            letters += 1

        # Count the sentences
        


main()
