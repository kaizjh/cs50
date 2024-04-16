#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string number = get_string("Number:");
    
    printf("%s\n", number);
    printf("%i\n", number[0] -48);
    printf("%i\n", number[1] -48);
    printf("%i\n", number[2]);
    printf("%i\n", number[3]);
    printf("%i\n", number[4]);
    printf("%i\n", number[5]);
}
