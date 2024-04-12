#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(int argc, string argv[])
{
    string s = get_string("String:");
    for(int i = 0; i < strlen(s); i++)
        {

            if(s[i] > 'a' && s[i] < 'z')
            {
                s[i] = s[i] - 32;
            }
        }
    printf("%s\n", s);
}
