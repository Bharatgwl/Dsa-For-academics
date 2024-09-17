#include <stdio.h>
void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    return;
}
void bubble_sort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    bubble_sort(arr);
    for (int i = 0; i < 5; i++)
    {

        printf("%d ", arr[i]);
    }

}