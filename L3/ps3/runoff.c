// A ranked-choice voting system
include <cs50.c>
#include <stdio.h>

typedef struct
{
    int vote;
    string name;
}
candidate;

int main(int argc, string argv[])
{
    // Get the candidates from the comman-line arguments
    if (argc < 2)
    {
        printf("Usage: ./runoff [candidate ...]");
        return 1;
    }

    candidate candidates[];
    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1] = argv[i];
    }

    // Get the number of voters
    // Get votes, every voters has rank 1,2,3, if get invalid vote, print the error, return
    // Calculate every candidate's votes in rank 1, if no candidate has more than 50% of the vote, then runoff to the rank 2, and so on
    // Print the winner
}
