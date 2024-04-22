// A ranked-choice voting system
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int MAX = 9;

typedef struct
{
    int vote;
    string name;
}
candidate;

candidate candidates[MAX];
int candidate_count;

string get_votes(int voter_count);

int main(int argc, string argv[])
{
    // Get the candidates from the comman-line arguments
    if (argc < 2)
    {
        printf("Usage: ./runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1].name = argv[i];
    }
    // Get the number of voters
    int voter_count = get_int("Number of voters: ");
    // Get votes, every voters has rank 1,2,3,..., if get invalid vote, print the error, return
    string votes = get_votes(voter_count);
    
    // Calculate every candidate's votes in rank 1, if no candidate has more than 50% of the vote, then runoff to the rank 2, and so on
    // Print the winner
}

// Get votes, every voters has rank 1,2,3, if get invalid vote, print the error, return
string get_votes(int voter_count)
{
    string votes[voter_count][candidate_count];
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            votes[i][j] = get_string("Rank %i: ", j + 1);

            int valid = 0;
            for (int k = 0; k < candidate_count; k++)
            {
                if (strcmp(votes[i][j], candidates[k].name) == 0)
                {
                    valid = 1;
                }
            }
            if (!valid)
                return "Invalid vote.";
        }
    }
    return votes[voter_count][candidate_count];
}
