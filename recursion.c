#include<cs50.h>
#include<stdio.h>

void draw(int n);

int main(void)
{
    //int height = get_int("Height:");
    draw(4);
}

void draw(int n)
{
    if(!n)
    {
        return;
    }

    draw(n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
