#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_word(int number);
int score(string p);

int main(void)
{
    string p1 = get_word(1);
    string p2 = get_word(2);

    int s1 = score(p1);
    int s2 = score(p2);
    if(s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if(s1 < s2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

//Prompt for the user for words and tuopper them
string get_word(int number)
{
    string p = get_string("Player %i:", number);
    for (int i = 0, n = strlen(p); i < n; i++)
        {
            if(p[i] < 65 || p[i] > 122 || (p[i] > 90 && p[i] < 97))
            {
                p[i] = 0;
                mark = 1;
            }
            p[i] = toupper(p[i]);
        }
    return p;
}

//Compute the score of the words.
int score(string p)
{
    int score = 0;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if ( p[i] == 'D' || p[i] == 'G')
        {
            score = score + 2;
        }
        else if (p[i] == 'B' || p[i] == 'C' || p[i] == 'M' || p[i] == 'P')
        {
            score = score + 3;
        }
        else if ( p[i] == 'F' || p[i] == 'H' || p[i] == 'V' || p[i] == 'W' || p[i] == 'Y')
        {
            score = score + 4;
        }
        else if( p[i] == 'A')
        {
            score = score + 5;
        }
        else if( p[i] == 'J' || p[i] == 'X')
        {
            score = score + 8;
        }
        else if( p[i] == 'Q' || p[i] == 'Z')
        {
            score = score + 10;
        }
        else
        {
            score++;
        }
    }
    return score;
}
