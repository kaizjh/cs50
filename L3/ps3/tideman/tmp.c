
// A function in lock_pairs by Irving, to judge the graph is cycle or not
bool is_cycle(int current, int seen[]);

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int seen[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        seen[i] = -1;
    }
    for (int i = 0; i < pair_count; i++)
    {
        if (!is_cycle(i, seen))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            seen[i] = i;
        }
    }
    return;
}

bool is_cycle(int current, int seen[])
{
    if (seen[0] == -1)
    {
        return false;
    }
    int begin_winner = pairs[current].winner;
    while (true)
    {
        bool current_changed = false;
        for (int i = 0; i < pair_count; i++)
        {
            if (pairs[seen[i]].loser == pairs[current].winner)
            {
                current = i;
                current_changed = true;
            }
        }
        if (!current_changed)
        {
            printf("%s\n", candidates[pairs[current].winner]);
            return false;
        }
        else if(pairs[current].loser == begin_winner)
        {
            return true;
        }
        printf("2");
    }
}




