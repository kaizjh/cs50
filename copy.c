#include<cs50.h>
#include <stdio.h>
#include<string.h>

int main(void)
{
    char *s = "hi!";
    char *t = malloc(strlen(s) + 1);

    for(int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = s[i];
    }

    printf("t:%s", t);
}
