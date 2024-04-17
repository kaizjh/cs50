#include <cs50.h>
#include <stdio.h>
#include <string.h>

float count(string s);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    float index = count(text);

    // Print the Grade X
}

/**Count the L, the average number of letters per 100 words in the text
 * And the S, the average number of sentences per 100 words in the text
 * Then compute the Coleman-Liau index
 */
float count(string s)
{
    float L = 0, S = 0, letters = 0, words = 0, sentences = 0;
    for(int i = 0, n = strlen(s); i < strlen(s); i++)
    {
        if ((s[i] < 'z' && s[i] > 'a') || (s[i] < 'Z' && s[i] > 'A'))
        {
            letters++;
        }
        if(s[i] == ' ')
        {
            words++;
        }
        if(s[i] == '.' || s[i] == '?' || s[i] == '!' || s[i] == ',' || s[i] == ';' || s[i] == '.')
        {
            sentences++;
        }
    }
    printf("%f %f %f\n", letters, words, sentences);
    L = letters / words * 100;
    S = sentences / words *100;
    float index = 0.0588 * L - 0.296 * S -15.8;
    r
}
