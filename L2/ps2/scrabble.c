#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        string p1 = get_string("Player 1:");
        for (int i = 0, n = strlen(p1); i < n; i++)
        {
            if(p1[i] < 65 || p1[i] > 122 || (p1[i] > 90 && p1[i] < 97))
            {
                printf("Please enter alphabets.")
            }
        }
    }
    string p2 = get_string("Player 2:");
}
