# There is no array, but list in Python
scores = [72, 73, 33]

average = sum(scores) / len(scores)
print(f"Average:{average}")

# This actually the shorthand version of this: scores = list(), which means create a empty list
scores = []

for i in range(3):
    score = int(input("Score:"))
    scores.append(score)

average = sum(scores) / len(scores)
print(f"Average:{average}")
