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
    int left = start;
    int right = mid + 1;
    for (int i = start; i < final; i++)
    {
        if (arr[left] <= arr[right])
        {
            sorted[left] = arr[left];
            right;
        }
        else
        {
            sorted[left] = arr[right];
            start--;
        }
    }
}
