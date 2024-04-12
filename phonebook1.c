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
    /**using this struct thing to replace the older one, seems kind of 'ugly', but learn to use the 'typedef struct' is the key point in here.
     * and we will learn a better way to update the code here, make it more efficient.
    */
    people[0].name = "Irving";
    people[0].number ="234-235-2552";
    people[1].name = "David";
    people[1].number ="344-355-5562";


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
