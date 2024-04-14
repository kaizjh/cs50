#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int *list = malloc(3*sizeof(int));
    list[0] = 0;
    list[1] = 1;
    list[2] = 2;

    int *tmp = realloc(list, 4*sizeof(int));
    if(tmp == NULL)
    {
        free(list);
        return 1;
    }
    list = tmp;
    list[3] = 3;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
}
