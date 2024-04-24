#include <cs50.h>
#include <stdio.h>

int main(void)
{
    merge_sort();
    return 0;
}

merge_sort(int start, int final, int arr[])
{
    // Base case
    if (start >= final)
    {
        return;
    }

    // Recursive case
    int mid = (final + start) / 2;
    // Merge_sort the left half (less than the mid half)
    merge_sort(start, mid);
    // Merge_sort the right half (more than the mid half)
    merge_sort(mid + 1, final);
    // After saparate all the half into the last one, time to merge them
    int len = final - start;
    int sorted[];
    for (int i = 0; i < len / 2; i++)
    {
        if (start < final - len)
        if (arr[start + i] <= arr[mid + i + 1])
        {
            sorted[start + i] = arr[start + i];
            mid--;
        }
        else
        {
            sorted[start + i] = arr[mid + i + 1];
            start--;
        }
    }
}
