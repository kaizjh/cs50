#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_word(int number);

int main(void)
{

    string d = strupr("sfdsf");
    printf("%s", d);
}

string get_word(int number)
{
    int mark;
    string p;
    do
    {
        mark = 0;
        p = get_string("Player %i:", number);
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if(p[i] < 65 || p[i] > 122 || (p[i] > 90 && p[i] < 97))
            {
                printf("Don't enter anything but alphabets.\n");
                mark = 1;
                break;
            }
        }
    }
    while (mark);
    return p;
}
