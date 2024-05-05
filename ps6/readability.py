text = input("Text: ")

# Compute the Coleman-Liau index
texts = text.lower()
# In Python, we can initialize variables like this, not in C
words, letters, sentences = 1, 0, 0
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
# Final computation
L = letters / words * 100
S = sentences / words * 100
index = 0.0588 * L - 0.296 * S - 15.8

# Print the Grade
grade = round(index)
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    for i in range(1,16):
        if i == grade:
            print(f"Grade: {grade}")
