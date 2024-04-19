#include <cs50.c>
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
    if (n = 1)
    {
        return step;
    }
    else if (n % 2)
    {
        n = 3 * n + 1;
        step++;
        collatz(n);
    }
    else
    {
        n = n / 2;
        step++;
        collatz(n);
    }
}
