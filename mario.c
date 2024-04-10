#include<cs50.h>
#include<stdio.h>

void print_grid(int n);
int get_size();

int main(void)
{
    int n = get_size();
    print_grid(n);
}

int get_size()
{
    int n;
    do
    {
        n = get_int("Size:");
    }
    while (n < 1);
    return n;
}

void print_grid(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
