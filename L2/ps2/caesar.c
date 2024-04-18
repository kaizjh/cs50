// Using Caesar's cipher to encrypt messages
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string p, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter one argument!\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plain = get_string("plaintext:  ");
    string cipher = encrypt(plain, argv[1]);

    printf("ciphertext: %s\n", cipher);
    return 0;
}

// Encrypt the plaintext with the algorithm: c = (p + k) % 26
string encrypt(string p, string key)
{
    // Allocate memory for the cipher string
    string cipher = p;
    // Convert string key to int k
    int k = atoi(key);

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        char c = p[i];
        if (c > 'A' && c < 'Z')
        {
            int j = c - 'A';
            cipher[i] ='A' + (j + k) % 26;
        }
        else if (c > 'a' && c < 'z')
        {
            int j = c - 'a';
            cipher[i] ='a' + (j + k) % 26;
        }
    }
    return cipher;
}
