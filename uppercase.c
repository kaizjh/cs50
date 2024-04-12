#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

int main(int argc, string argv[])
{
    string s = get_string("String:");
    for(int i = 0; i < strlen(s); i++)
        {
            printf("%c", toupper(s[i]));
        }
    printf("\n");
}
