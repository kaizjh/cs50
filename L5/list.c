#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int *list = malloc(3*sizeof(int));
    list[0] = 0;
    list[1] = 1;
    list[2] = 2;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
