#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    int *list = malloc(3*sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    
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
    free(list);
    return 0;
}
