void tabulate(void)
{
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            int p = preferences[voter][rank];
            if (candidates[p].eliminated)
            {
                rank++;
                break;
            }
            else
            {
                candidates[p].votes++;
            }
        }
    }
    return;
}



// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int rank = 0;
        if (!candidates[i].eliminated)
        {
            for (int voter = 0; voter < voter_count; voter++)
            {
                if (preferences[voter][rank] == i)
                {
                    candidates[i].votes++;
                }
            }
        }
        else
        {
            rank++;
        }
    }
    return;
}
