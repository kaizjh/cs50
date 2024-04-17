// Using Caesar's cipher to encrypt messages
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string encrypt(string s, int a);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter one argument!");
        return 1;
    }

    for (int i = 0, n= strlen(argv); i < n; i++)
    {
        if (argv[i] < '0' || argv[i] > '9')
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    string plain = get_string("plaintext:  ");
    string cipher = string encrypt(plain, int(argv));

    printf("ciphertext: %s\n", cipher);
    return 0;
}

// Encrypt the plaintext with the algorithm: c = (p + k) % 26
string encrypt(string p, int k)
{
    string cipher[];
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        char c = toupper(p[i]);
        int j = c - 64;
        cipher[i] = (j + k) % 26;
    }
    return cipher;
}
