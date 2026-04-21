#include <stdio.h>

int main()
{
    int arr1[10], arr2[10], arr3[20];
    int i, j, k, m, n;

    printf("Enter the number of elements in Array 1: ");
    scanf("%d", &m);

    printf("Enter the elements of Array 1:\n");
    for(i = 0; i < m; i++)
    {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter the number of elements in Array 2: ");
    scanf("%d", &n);

    printf("Enter the elements of Array 2:\n");
    for(j = 0; j < n; j++)
    {
        printf("arr2[%d] = ", j);
        scanf("%d", &arr2[j]);
    }

    // Merging: Copy arr1 into arr3
    for(i = 0; i < m; i++)
        arr3[i] = arr1[i];

    // Copy arr2 into arr3 after arr1
    for(j = 0; j < n; j++)
        arr3[i + j] = arr2[j];

    // Total elements in merged array
    k = m + n;

    printf("\nMerged Array is:\n");
    for(i = 0; i < k; i++)
        printf("%d  ", arr3[i]);

    printf("\n");

    return 0;
}