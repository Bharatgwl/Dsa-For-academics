//linear probing h%k

#include <stdio.h>
int main()
{
    int collision = 0;
    int k;
    if (scanf("%d", &k) != 1 || k <= 0)
    {
        printf("Invalid input");
        return 1;
    }

    int arr[k];
    int ans[k];
    for (int i = 0; i < k; i++)
        ans[i] = -1;
    for (int i = 0; i < k; i++)
    {
        int d;
        if (scanf("%d", &d) != 1 || d < 0)
        {
            printf("Invalid input");
            return 1;
        }
        arr[i] = d;
    }

    for (int i = 0; i < k; i++)
    {
        int rem = arr[i] % k;
        int m = rem;
        while (ans[m] != -1)
        {
            m = (m + 1) % k;
            collision++;
        }
        ans[m] = arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    printf("collisions: %d", collision);
    return 0;
}
