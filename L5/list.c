#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./list numbers ...\n");
    }

    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        n->number = num;
        n->next = list;

        list = n;
    }

    // While loops and for loops can always substitute each other
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i\n", ptr -> number);

    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
