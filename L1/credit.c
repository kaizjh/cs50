#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string number = get_string("Number:");

    int sum = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        sum = sum + number[i] * 2;
    }
    for (int j = 1; j < 16; j = j + 2)
    {
        sum = sum + number[j];
    }

    printf("%s\n", number);
    printf("%i\n", number[0] -48);
}
