#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int scores[1024];
    /**garbage values are indeed a term, which means that a variable you might have defined
     * that you might have declared but never give it a explicit value (initialized).
     * then the compile will poke around in the memory, and who knows what there going be?*/
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
