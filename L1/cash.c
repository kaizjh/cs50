#include <cs50.h>
#include <stdio.h>

void greedy(int n);

int main(void)
{
    int co;
    do
    {
        co = get_int("Change owed:");
    }while(co < 1);

    greedy(co);
}

void greedy(int n)
{
    int counts = 0;
    for(; n > 24; counts++)
    {
        n = n - 25;
    }
    for(; n > 9; counts++)
    {
        n = n - 10;
    }
    for(; n > 4; counts++)
    {
        n = n - 5;
    }
    for(; n > 0; counts++)
    {
        n = n - 1;
    }

    printf("%i\n", counts);
}
