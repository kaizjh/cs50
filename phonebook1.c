#include<cs50.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];
    people[].name = {"Irving", "David"};
    people[].number ={"234-235-2552", "235-255-2352"};

    string s = get_string("name:");
    for(int i = 0; i < 2; i++)
    {
        if(!strcmp(s, people[i].name))
        {
            printf("Found, %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
