#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned long int number = get_int("Number:");
    printf("%lu\n", number);
}
