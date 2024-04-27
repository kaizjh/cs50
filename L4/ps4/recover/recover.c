#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE *input = fopen(argv[1],"r");
    if (input == NULL)
    {
        printf("Can not open the input file!");
        return 1;
    }


    uint8_t buffer[512];
    int i = 0;
    char s[9];
    FILE *output;

    while (fread(buffer, sizeof(uint8_t), 512, input) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // Close the former output file, if there is one
            if (i > 0)
                fclose(output);

            // Check the number of jpg file, make a name for it
            if (i < 10)
            {
                sprintf(s, "00%i.jpg", i);
            }
            else if (i < 100)
            {
                sprintf(s, "0%i.jpg", i);
            }
            else
            {
                sprintf(s, "%i.jpg", i);
            }
            i++;

            // Open a new output file
            output = fopen(s,"w");
            if (output == NULL)
            {
                printf("Can not open the output file!");
                return 1;
            }
        }

        // Write things into the file, if next file is opened, then write in the new file
        fwrite(buffer, sizeof(uint8_t), 512, output);
    }

    fclose(input);
}
