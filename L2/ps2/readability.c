#include <cs50.h>
#include <stdio.h>

int index(string s);

int main(void)
{
    // Prompt the user for some text
    int text = get_string("Text: ");

    int index = count(text);
    // Print the Grade X
}

/**Count the L, the average number of letters per 100 words in the text
 * And the S, the average number of sentences per 100 words in the text
 * Then compute the Coleman-Liau index
 */
int index(string s)
{
    int L = 0, n = strlen(s);
    for(int i = 0; i < strlen(s); i++)
    {
        if ((p[i] < 65 && p[i] > 90) || (p[i] < 122 && p[i] > 97))
        {
            letter++;
        }
    }
}
