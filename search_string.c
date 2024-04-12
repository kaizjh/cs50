#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string strings[] = {"echo", "flash", "great", "marvel", "amazing", "fxxk"};
    string s = get_string("string:");
    for (int i = 0; i < 6; i++)
    /**if you do copy-paste, it is really important to look at the loops,
     * to aviod getting the error"Segmention fault(core dumped)", in here, it means i is way too big.
    */
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
