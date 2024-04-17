#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_word_and_toupper(int number);

int main(void)
{
    string p1 = get_word_and_toupper(1);
    string p2 = get_word_and_toupper(2);
    printf("%s %s\n", p1, p2);

}

string get_word_and_toupper(int number)
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
            p[i] = toupper(p[i]);
        }
    }
    while (mark);

    return p;
}
