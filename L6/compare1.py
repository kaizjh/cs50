# In python, a variable is unchangable, technically, immutable,
# even if we do "s = s.lower()", we just get the copy of s
s = input("s: ")

# capitalize() only capitalize the first letter in a word, is different from upper()
t = s.capitalize()

print(f"s: {s}")
print(f"t: {t}")

print()

s1 = input("s1: ")
t1 = input("t1: ")

if s1 == t1:
    print("Same")
else:
    print("Different")
