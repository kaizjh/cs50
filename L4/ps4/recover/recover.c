// A program to recover some deleted JEPG in card.raw file (or in the memory, maybe)

// This code implementation is actually by myself, with a little direction from cs50 and chatgpt.
// And when it actually runned, the 50 pictures fixed and get into my eyes, I feel proud and amazing!
// I am proud of myself, I am amazing at the computer science.
// I know the pictures' principle (a little) underneath the hood; I see the pictures from far far away, after my own efforts, ofc, and cs50's efforts.
// There are 50 pictures, I have seen all of them one by one, although, they are a little indistinct, I have to say:they are beautiful!
// Thank you for meeting cs50!I love cs50! --Irving

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
    FILE *output = NULL;

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

        // Write things into the output file, if there is one
        if (output != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, output);
        }
    }

    fclose(input);
    fclose(output);
}
