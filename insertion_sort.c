#include <stdio.h>
void insertion_sort(int arr[])
{
    for (int i = 1; i < 5; i++)
    {
        int min_index = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > min_index){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=min_index;
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    insertion_sort(arr);
    for (int i = 0; i < 5; i++)
    {

        printf("%d ", arr[i]);
    }
}
