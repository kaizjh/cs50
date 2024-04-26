#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE *input = fopen(argc[1],"r");
    if (input = NULL)
    {
        printf("Can not open the input file!");
        return 1;
    }
    FILE *output = fopen("1.jpeg","w");
    if (input = NULL)
    {
        printf("Can not open the output file!");
        return 1;
    }

    uint8_t buffer[512];
    do
    {
        fread(buffer, sizeof(uint8_t), 512, input);
        for (int i = 0; i < 4; i++)
        {
            
        }

    }
    while()
}
