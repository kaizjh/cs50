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
    char *s = "Irving";
    printf("%s\n", s);
    printf("%p\n", s);

    printf("%p\n", &s);
    printf("%p\n", &s[0]);

}
