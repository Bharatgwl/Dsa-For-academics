#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int max = arr[0];

    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Max element: %d", max);
    return 0;
}
