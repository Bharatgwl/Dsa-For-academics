// void heapsort(int *heap, int *ans, int *n)
// {
//     if (*n == 0)
//     {
//         printf("Heap is empty!\n");
//         return;
//     }

//     int minValue = heap[0];
//     ans[0] = minValue; // Store the min value in the answer array

//     // Move the last element to the root of the heap
//     heap[0] = heap[*n - 1];
//     (*n)--; // Decrease the heap size by 1
    
//     // Reheapify down the heap after removing the root
//     for (int i = (*n) / 2 - 1; i >= 0; i--)
//     {
//         heapifyDown(heap, *n, i);
//     }
// }