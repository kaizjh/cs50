#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char *s = "hi!";
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n =strlen(s) + 1; i < n; i++)
    /**for(int i = 0; i < strlen(s); i++), here is a little promotion above,
     * just make sure there is no 'calling function' in the condition (middle of the for loop) ,
     * because we don't need to call it again again and again (in the middle of the loop).*/
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);
    printf ("t:%s\n", t);
}
