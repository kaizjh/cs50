#include <cs50.h>
#include <stdio.h>

void merge_sort(int start, int final, int arr[]);

int main(void)
{
    int num = get_int("Numbers of the array: ");
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = get_int("Number %i: ", i + 1);
    }
    merge_sort(0, num - 1, arr);

    printf("Sorted:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int start, int final, int arr[])
{
    // Base case
    if (start >= final)
    {
        return;
    }

    // Recursive case
    int mid = (final + start) / 2;
    // Separate the left half (less than the mid half)
    merge_sort(start, mid, arr);
    // Separate the right half (more than the mid half)
    merge_sort(mid + 1, final, arr);

    int left = start;
    int right = mid + 1;
    int temp[final - start + 1];
    for (int i = 0; i < final - start + 1; i++)
    {
        if (left > mid)
        {
            temp[i] = arr[right++];
        }
        else if (right > final)
        {
            temp[i] = arr[left++];
        }
        else if (arr[left] < arr[right])
        {
            temp[i] = arr[left++];
        }
        else
        {
            temp[i] = arr[right++];
        }
    }

    // Copy elements from temp back to arr
    for (int i = 0; i < final - start + 1; i++)
    {
        arr[start + i] = temp[i];
    }
}
