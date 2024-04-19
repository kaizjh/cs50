// Using recursion to get the step of the collatz algorithm
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
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2)
    {
        return 1 + collatz(3 * n + 1); // There no need to make a variable(e.g. int step;) to record the steps
    }
    else
    {
        return 1 + collatz(n / 2); // Maybe named this function collatz_steps is more suitable, and more understandable.
    }
}
