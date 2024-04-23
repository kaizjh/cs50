#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Initializing the preferences[i][j] by Irving
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
// I think this function is perfect for now --Irving
void record_preferences(int ranks[])
{
    int seen[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        seen[i] = 0; // Initialize seen array
    }

    for (int rank = 0; rank < candidate_count; rank++)
    {
        for (int i = 0; i < candidate_count; i++)
            {
                if (ranks[rank] == i)
                {
                    seen[i] = 1; // Mark i(candidate[i]) as seen, make sure this candidate never!!! appear in j
                    for (int j = 0; j < candidate_count; j++)
                    {
                        if (!seen[j])
                        {
                            preferences[i][j]++;
                        }
                    }
                    break;
                }
            }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++, k++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            pair tmp;
            int imargin = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            int jmargin = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (imargin < j margin)
            {
                pair tmp = pair pairs[i];
                pair pairs[i] = pair pairs[j];
                pair pairs[j] = pair tmp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int seen[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        seen[i] = 0; // Initialize seen array
    }

    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (!seen[i])
        {
            locked[pairs[i].winner][pairs[i].loser];
            seen[i] = 1;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int winner;
    for
    return;
}
