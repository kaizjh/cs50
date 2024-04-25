#include <cs50.h>
#include <stdio.h>

void merge_sort(int start, int final, int arr[]);

int sorted[9];

int main(void)
{
    int num = get_int("Numbers of the array: ");
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = get_int("Number %i: ", i + 1);
    }
    merge_sort(0, num, arr);

    printf("Sorted:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%i ", sorted[i]);
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
    // Saparate the left half (less than the mid half)
    merge_sort(start, mid, arr);
    // Saparate the right half (more than the mid half)
    merge_sort(mid + 1, final, arr);
    // After saparate all the half into the last one, time to merge them
    int left = start;
    int right = mid + 1;
    for (int i = start; i < final; i++)
    {
        if ((arr[left] < arr[right] || right > final) && left < mid + 1)
        {
            left++;
        }
        else
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

            right++;
        }
    }
}
