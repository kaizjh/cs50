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
            }
            else
            {
                candidates[p].votes++;
            }
        }
    }
    return;
}
