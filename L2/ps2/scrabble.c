#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int mark;
    do
    {
        mark = 0;
        string p1 = get_string("Player 1:");
        for (int i = 0, n = strlen(p1); i < n; i++)
        {
            if(p1[i] < 65 || p1[i] > 122 || (p1[i] > 90 && p1[i] < 97))
            {
                printf("Don't enter anything but alphabets.\n");
                mark = 1;
                break;
            }
        }
    }
    while (mark);
    string p2 = get_string("Player 2:");
}
