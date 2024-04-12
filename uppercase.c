#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(int argc, string argv[])
{
    string s = argv[];
    if(argc < 2)
    {
        printf("Missing the command line argument!");
    }
    else
    {
        for(int i = 0; i < strlen(argv); i++)
        {

            if(argv[i] > 'a' && argv[i] < 'z')
            {
                argv[i] = argv[i] - 32;
            }
        }
    }
    printf("%s", argv);
}
