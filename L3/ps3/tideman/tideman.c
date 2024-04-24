#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
        // Initialize seen array
        seen[i] = 0;
    }

    for (int rank = 0; rank < candidate_count; rank++)
    {
        for (int i = 0; i < candidate_count; i++)
            {
                if (ranks[rank] == i)
                {
                    // Mark i(candidate[i]) as seen, make sure this candidate never!!! appear in j
                    seen[i] = 1;
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
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            pair tmp;
            int imargin = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            int jmargin = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (imargin < jmargin)
            {
                tmp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = tmp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Iterate over sorted pairs and add them to locked if no cycle is detected
    for (int i = 0; i < pair_count; i++)
    {
        // Assume the pair is locked
        locked[pairs[i].winner][pairs[i].loser] = true;

        // Check if adding the pair creates a cycle
        bool visited[candidate_count];
        for (int j = 0; j < candidate_count; j++)
        {
            visited[j] = false;
        }

        // Start from the winner of the current pair
        int current = pairs[i].winner;
        while (current != -1)
        {
            // If the current candidate is already visited, a cycle is detected
            if (visited[current])
            {
                // Unlock the last locked pair
                locked[pairs[i].winner][pairs[i].loser] = false;
                break;
            }

            // Mark the current candidate as visited
            visited[current] = true;

            // Move to the next candidate who is defeated by the current one
            int next = -1;
            for (int j = 0; j < candidate_count; j++)
            {
                if (locked[j][current])
                {
                    next = j;
                    break;
                }
            }
            current = next;
        }
    }
}



// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner_found = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                winner_found = false;
                break;
            }
        }
        if (winner_found)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
