#include <cs50.h>
#include <stdio.h>

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
    for(; n > 24; )
    {
        counts = n % 25;
        n = n - i * n;
    }
    
}
