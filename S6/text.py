text = "In the great green room"

for word in text.split():
    print(word)

print("---------------1--------------")

for word in text.split()[2:]:
    print(word)

print("----------------2-------------")

words = text.split()
print(words[1:3])
