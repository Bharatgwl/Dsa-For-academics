#include <stdio.h>
int main()
{
    int a;
    // printf("%d",a);
    scanf("%d", &a);
    printf("a is : %d", a);
    printf("\n");
    int*ptr=&a;

    printf("%zu", sizeof(ptr));
}