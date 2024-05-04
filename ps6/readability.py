def main():
    text = []
    text = input("Text: ")
    
    texts = text.lower()
    print(texts)

    words = 1
    for c in texts:
        # Count the words
        if c == ' ':
            words += 1
        # Count the letters


main()
