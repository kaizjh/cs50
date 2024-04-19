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
        printf("Key must be 26 characters, and each letter exactly once\n");
        return 1;
    }

    int sum = 0;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        int t = toupper(argv[1][i]);
        sum = sum + t;
    }
    // If each letter exactly once, sum == 2015
    if (sum != 2015)
    {
        printf("Key must be 26 characters, and each letter exactly once\n");
        return 1;
    }
    string key = argv[1];

    string plain = get_string("plaintext:  ");

    string cipher = substitute(plain, key);
    printf("ciphertext: %s", cipher);
}

// Substitute the plaintext
string substitute(string plain, string key)
{
    string sub = NULL;
    int number = 0;

    for (int j = 0, n = strlen(plain); j < n; j++)
    {
        if (islower(plain[j]))
        {
            number = plain[j] - 96;
            sub[j] = key[number];
        }
        else if (isupper(plain[j]))
        {
            number = plain[j] -64;
            sub[j] = key[number];
        }
    }

    return sub;
}
