import sys

# If we "from sys import argv" then we can just use "argv" rather than "sys.argv"
# And "sys.argv" always tells us where the function it comes from, so I think this style is good for me --Irving
if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
