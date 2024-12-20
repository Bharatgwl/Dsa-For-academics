#include <stdio.h>
int count = 0;
int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[j];
            arr[j] = temp;
            i++;
            count++;
        }
    }
    int temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;
    // count++;
    return i + 1;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partion_index = partition(arr, low, high);
        quicksort(arr, low, partion_index - 1);
        quicksort(arr, partion_index + 1, high);
    }
}
int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int arr[10] = {1, 5, 0, 4, 8, 9, 7, 2, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("%d ", count);
}