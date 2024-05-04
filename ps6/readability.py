def main():
    text = input("Text: ")

    texts = text.lower()
    words = 1
    letters = 0
    sentences = 0
    for c in texts:
        print(c)
        # Count the words
        if c == ' ':
            words += 1
        # Count the letters
        if c >='a' and c <= 'z':
            letters += 1

        # Count the sentences
        if c == '!' or c == '?' or c == '.':
            sentences += 1
    print(words, letters, sentences)

    L = letters / words * 100
    print(L)
    S = sentences / words * 100
    print(S)
    index = 0.0588 * L - 0.296 * S - 15.8
    


main()
