#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string name[] = {"Irving", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-233-2653"};

    string s = get_string("name:");
    for(int i = 0; i < 2; i++)
    {
        if(!strcmp(s, name[i]))
        {
            printf("Found, %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found");
    return 1;
}
