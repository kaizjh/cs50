import sys

# If we "from sys import argv" then we can just use argv rather than sys.argv
if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
