#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main()
{
    int n = get_int("Enter a positive integer:");
    int s = collatz(n);
}

int collatz(int n)
{
    int step = 1;
    if (n == 1)
    {
        return step;
    }
    else if (n % 2)
    {
        step++;
        collatz(3 * n + 1);
    }
    else
    {
        step++;
        collatz(n / 2);
    }
}
