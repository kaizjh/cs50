#include <stdio.h>
#include <stdlib.h>

typedef struct node //node in here is kind of wild, but it is like a function declaration, it must be here.
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        
    }
}
