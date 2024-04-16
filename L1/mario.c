#include <cs50.h>
#include <stdio.h>

int main()
{
    int h;
    do
    {
        h = get_int("Height:");
    }
    while (h <= 0);

    for (int i = 0; i < h; i++)
    {
        for (int n = 0; n < h - i - 1; n++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
