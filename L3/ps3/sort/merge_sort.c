#include <cs50.h>
#include <stdio.h>

int main(void)
{
    merge_sort();
    return 0;
}

merge_sort(int start, int final, int arr[])
{
    if (start >= final)
    {
        return;
    }

    int mid = (final + start) / 2;
    merge_sort(start, mid);
    merge_sort(mid, final);


}
