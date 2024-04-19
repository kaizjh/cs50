#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main()
{
    int n = get_int("Enter a positive integer:");
    int s = collatz(n);
    printf("%i\n", s);
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
        return collatz(3 * n + 1);
    }
    else
    {
        step++;
        return collatz(n / 2);
    }
}
