#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned long int number = get_long("Number:");
    printf("%lu\n", number);
}
