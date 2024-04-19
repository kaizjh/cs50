// Encrypt the plaintext by using the 26-character key to substitute the plaintext
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
        printf("Key must be 26 alphabetic characters, and each letter exactly once\n");
        return 1;
    }

    int seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        char c = toupper(argv[1][i]);  // Convert to uppercase for simplicity
        if (!isalpha(c))
        {
            printf("Key must be 26 alphabetic characters, and each letter exactly once\n");
            return 1;
        }
        else if (seen[c - 'A'])
        {
            printf("Key must be 26 alphabetic characters, and each letter exactly once\n");
            return 1;
        }
        seen[c - 'A'] = 1;  // Mark this character as seen
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
    // Allocate memory for the sub string
    string sub = plain;
    int number = 0;

    for (int j = 0, n = strlen(plain); j < n; j++)
    {
        if (islower(plain[j]))
        {
            number = plain[j] - 97;
            sub[j] = tolower(key[number]);
        }
        else if (isupper(plain[j]))
        {
            number = plain[j] -65;
            sub[j] = toupper(key[number]);
        }
    }

    return sub;
}
