#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char *s = "hi!";
    char *t = malloc(strlen(s) + 1);

    for(int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);
    printf("t:%s\n", t);
    free t;
}
