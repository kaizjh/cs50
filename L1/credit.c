#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string number = get_string("Number:");

    printf("%i", number.length);
}
