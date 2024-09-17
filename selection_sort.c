#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void selection_sort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        int min_elem = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min_elem])
            {
                min_elem = j;
            }
        }
        swap(&arr[i], &arr[min_elem]);
    }
    return;
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    selection_sort(arr);
    for (int i = 0; i < 5; i++)
    {

        printf("%d ", arr[i]);
    }
}