void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = (int *)malloc(len1 * sizeof(int));
    int *second = (int *)malloc(len2 * sizeof(int));

    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy any remaining elements from `first`
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy any remaining elements from `second`
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Free dynamically allocated memory
    free(first);
    free(second);
}

// Sort the array using the Merge Sort algorithm
void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // Recursively sort the first and second halves
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}
int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}