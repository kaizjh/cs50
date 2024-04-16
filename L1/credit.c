#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number:");



    if (sum % 10)
    {
        printf("INVALID\n");
    }
    else
    {

    }
}

// Calculate Checksum
int calculate(string)
{
    int sum = 0, length = strlen(number);
    for (int i = 0; i < length; i = i + 2)
    {
        if (number[i] > 52)
        {
            sum = sum + 1 + (number[i] -48) * 2 - 10;
        }
        else
        {
            sum = sum + (number[i] - 48) * 2;
        }
    }

    for (int j = 1; j < length; j = j + 2)
    {
        sum = sum + number[j] - 48;
    }
    return sum;
}
