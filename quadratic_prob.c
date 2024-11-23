// quadratic probing h%k

#include <stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    int collision = 0;
    int arr[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans[k];
    for (int i = 0; i < k; i++)
    {
        ans[i] = -1;
    }
    for (int i = 0; i < k; i++)
    {
        int rem = arr[i] % k;
        int m = rem;
        int sq = 1;
        while (ans[m] != -1)
        {
            collision++;
            m = (rem + sq * sq) % k;
            sq++;
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
