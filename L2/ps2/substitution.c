#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string substitute(string plain, string key);

int main(int argc, string argv[])
{
    // Checking the command-line argument get the 26-character key and each letter exactly once
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }

    int seen[26] = {0}; // Array to keep track of seen characters in the key

    for (int i = 0; i < 26; i++)
    {
        char c = toupper(argv[1][i]); // Convert to uppercase for simplicity
        if (!isalpha(c))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
        if (seen[c - 'A'])
        {
            printf("Key must not contain duplicate characters\n");
            return 1;
        }
        seen[c - 'A'] = 1; // Mark character as seen
    }

    string key = argv[1];

    string plain = get_string("plaintext:  ");

    string cipher = substitute(plain, key);
    printf("ciphertext: %s\n", cipher);

    return 0;
}

// Substitute the plaintext
string substitute(string plain, string key)
{
    string sub = plain;

    for (int j = 0, n = strlen(plain); j < n; j++)
    {
        char c = plain[j];
        if (islower(c))
        {
            sub[j] = tolower(key[c - 'a']);
        }
        else if (isupper(c))
        {
            sub[j] = toupper(key[c - 'A']);
        }
    }

    return sub;
}
