#include <stdio.h>
#include <stdlib.h>

typedef struct node
//node in here is kind of wild, but it is like a function declaration, it must be here.
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    //why 'int i = 1' here not 'int i = 0' is that the first value in argv is actually the program's name.
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return 1;
        }
        n -> number = number;
        n -> next = NULL;

        n -> next = list;
        list = n;
    }

    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr -> number);
        list = list -> next;
    }

}
