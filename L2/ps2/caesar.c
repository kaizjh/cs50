// Using Caesar's cipher to encrypt messages

#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Prompt user to get the plaintext
// Encrypt the plaintext with the algorithm: c = (p + k) % 26;
// print the ciphertext
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
    
}

