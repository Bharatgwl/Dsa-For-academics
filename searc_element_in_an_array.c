#include <stdio.h>

void search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at index %d", i);
            return;
        }
    }
    printf("Element not found");
}
int main()
{
        int arr[5] = {1, 2, 3, 4, 5};
        int n = 5;
        int key;
        scanf("%d", &key);
        search(arr, n, key);
   
}