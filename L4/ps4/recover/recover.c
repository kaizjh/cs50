#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename.raw\n");
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

    typedef uint8_t BYTE;
    typedef BYTE512_t BLOCK;
    fread(buffer, )
}
