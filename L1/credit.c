#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate(string s);
int check(int sum, string s);

int main(void)
{
    string number = get_string("Number:");

    int sum = calculate(number);
    int result = check(sum, number);
    //printf the result
    switch (result)
    {
        case 1:
        case 2:
            printf("INVALID\n");
            break;
        case 3:
            printf("AMEX\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
    }
}

// Calculate Checksum
int calculate(string s)
{
    int sum = 0, length = strlen(s);
    for (int i = 0; i < length; i = i + 2)
    {
        if (s[i] > 52)
        {
            sum = sum + 1 + (s[i] -48) * 2 - 10;
        }
        else
        {
            sum = sum + (s[i] - 48) * 2;
        }
    }

    for (int j = 1; j < length; j = j + 2)
    {
        sum = sum + s[j] - 48;
    }
    return sum;
}

//Check for Card Length and Starting Digits
int check(int sum, string s)
{
    int start = s[0] - 48;
    int next = s[1] - 48;
    int length = strlen(s);

    if (sum % 10)
    {
        return 1;
    }
    else if (start == 3 && length > 12 && length < 17)
    {
        return 3;
    }
    else if (start == 4 && next == )
    {
        return 4;
    }
    else if (start == 5)
    {
        return 5;
    }
    else
    {
        return 2;
    }
}
