#include <cs50.h>
#include <stdio.h>

int index(string s);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    int index = count(text);

    // Print the Grade X
}

/**Count the L, the average number of letters per 100 words in the text
 * And the S, the average number of sentences per 100 words in the text
 * Then compute the Coleman-Liau index
 */
int count(string s)
{
    float L = 0, S = 0, letters = 0, words = 0, sentences = 0;
    for(int i = 0, n = strlen(s); i < strlen(s); i++)
    {
        if ((p[i] < 'z' && p[i] > 'a') || (p[i] < 'Z' && p[i] > 'A'))
        {
            letters++;
        }
        if(p[i] == ' ')
        {
            words++;
        }
        if(p[i] == '.' || p[i] == '?' || p[i] == '!' || p[i] == ',' || p[i] == ';' || p[i] == '.' ||)
        {
            sentences++;
        }
    }
    printf("%f %f %f\n", letters, words, sentences);
    L = letters / words * 100;
    S = sentences / words *100;
    index = 0.0588 * L - 0.296 * S -15.8

}
