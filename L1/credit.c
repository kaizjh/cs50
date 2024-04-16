#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string number = get_string("Number:");

    int sum;
    for (int i = 0; i < 16; i = i + 2)
    {
        if (number[i] > 52)
        {
            sum = sum + 1 + (number[i] -48) * 2 - 10;
        }
        else
        {
            sum = sum + number[i] - 48;
        }
    }

    for (int j = 1; j < 16; j = j + 2)
    {
        sum = sum + number[j] - 48;
    }

    if (sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
