/** with the 'training wheel', aka. <cs50.h>
#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", n);
    printf("%p\n", &n);
    printf("%p\n", p);
}
*/
#include <stdio.h>

int main(void)
{
    char *s = "Irv";
    printf("%s\n", s);
    printf("%p\n\n", &s);

    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);
    printf("%p\n", &s[5]);
    
}
