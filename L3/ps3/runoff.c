// A ranked-choice voting system
include <cs50.c>
#include <stdio.h>

const int MAX = 9;

typedef struct
{
    int vote;
    string name;
}
candidate;

candidate candidates[MAX]
int candidate_cout;

int main(int argc, string argv[])
{
    // Get the candidates from the comman-line arguments
    if (argc < 2)
    {
        printf("Usage: ./runoff [candidate ...]");
        return 1;
    }

    candidate_cout = 

    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1] = argv[i];
    }
    // Get the number of voters
    int voter_count = get_int("Number of voters: ");
    // Get votes, every voters has rank 1,2,3, if get invalid vote, print the error, return
    get_votes();
    // Calculate every candidate's votes in rank 1, if no candidate has more than 50% of the vote, then runoff to the rank 2, and so on
    // Print the winner
}

// Get votes, every voters has rank 1,2,3, if get invalid vote, print the error, return
get_votes(int voter_count, int )
{
   string votes[][]
}
