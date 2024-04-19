// Encrypt the plaintext by using the 26-character key to substitute the plaintext
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Using command-line argument to get the 26-character (each letter exactly once) key
// Prompt user to get the plaintext
// Encrypt the plaintext with substitution
// Print the ciphertext (preserve the case in plaintext)

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 characters, and each letter exactly once");
        return 1;
    }
    int sum = 0;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        int t = toupper(argv[1][i]);
        sum = sum + t;
    }
    if (sum != 2015)
    {
        printf("Key must be 26 characters, and each letter exactly once");
        return 1;
    }
}
