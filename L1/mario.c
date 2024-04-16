#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height:");
    }
    while (h <= 0);

    for (int i = 0; i < h; i++)
    {
        for (int n = 1; n < h - i; n++)
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
