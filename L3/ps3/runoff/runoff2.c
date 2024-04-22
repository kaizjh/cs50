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



int max_num = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        if (max > candidates[j].votes)
        {
            max_num++;
        }
    }
    if (max_num == 1)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (max == candidates[k].votes)
            {
                printf("%s\n", candidates[k].name);
            }
        }
        return true;
    }


    if (candidates[i].eliminated)
        {
            continue;
        }
        else
        {
            if (min > candidates[i].votes)
            {
                min = candidates[i].votes;
            }
        }
