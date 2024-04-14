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
    if(argc < 2)
    {
        printf("Missing command line arguments!\n");
        return 1;
    }
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
        //equals '(*n).number = number', the code above is obviously more efficient and more intuitive (just like a image).
        n -> next = NULL;

        n -> next = list;
        list = n;
    }

    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr -> number);
        ptr = ptr -> next;
    }
    free(list);
    return 0;
}
