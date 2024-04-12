#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string strings[] = {"echo", "flash", "great", "marvel", "amazing", "fxxk"};
    string s = get_string("string:");
    for (int i = 0; i < 6; i++)
    {
        if(!strcmp(strings[i], s))
        {
            printf("Founded!\n");
            return 0;
        }

    }
    printf("Not founded!\n");
    return 1;
}
