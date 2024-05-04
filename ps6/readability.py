def main():
    text = []
    text = input("Text: ")
    text.lower()
    print(text)

    words = 1
    for c in text:
        # Count the words
        if c == ' ':
            words += 1
        # Count the letters
        

main()
