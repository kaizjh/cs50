#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number:");

    int sum = calculate(number);


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

    if (start == 3)
    {
        return 3;
    }
    else if (start == 4)
    {
        return 4;
    }
    else if (start == 5)
    {
        return 5;
    }
    else if (sum % 10)
    {
        return 6;
    }
    else
    {
        return 7;
    }
}
