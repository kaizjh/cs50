#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number:");

    printf("%lu", strlen(number));
}
