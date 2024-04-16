#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned long long int number = get_int("Number:");
    printf("%llu\n", number);
}
