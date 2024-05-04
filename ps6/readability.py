text = input("Text: ")

texts = text.lower()
words = 1
letters = 0
sentences = 0
for c in texts:
    # Count the words
    if c == ' ':
        words += 1
    # Count the letters
    if c >='a' and c <= 'z':
        letters += 1

    # Count the sentences
    if c == '!' or c == '?' or c == '.':
        sentences += 1

L = letters / words * 100
S = sentences / words * 100
index = 0.0588 * L - 0.296 * S - 15.8
print(index)

