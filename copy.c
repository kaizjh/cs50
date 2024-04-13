#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char *s = "hi!";
    if (s == NULL) //when you get a super super big string, then you probably get a NULL.
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n =strlen(s) + 1; i < n; i++)
    /**for(int i = 0; i < strlen(s); i++), here is a little promotion above,
     * just make sure there is no 'calling function' in the condition (middle of the for loop) ,
     * because we don't need to call it again again and again (in the middle of the loop),
     * then my code will be more efficient!*/
    {
        t[i] = s[i];
    }
    /**this for loop above actually can be replaced by
     * strcpy(t, s);
     * just use someone's experience, and make my code more efficient.
    */

    t[0] = toupper(t[0]);
    printf ("t:%s\n", t);
    free(t);
}
