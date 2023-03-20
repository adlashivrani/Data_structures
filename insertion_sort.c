/* C Program to sort an array in ascending order using Insertion Sort */
#include <stdio.h>
void insertion_sort(int*, int);
int main()
{
    int n;
	int i;
	int j;
    int arr[64];
    printf("\nEnter number of elements\n");
    scanf("%d", &n);
    printf("\nEnter %d integers\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
	insertion_sort(arr, n);
	return 0;
}
void insertion_sort(int arr[], int n)
{
	int i;
	int j;
	int temp;
    for (i = 1; i < n; i++) 
    {
		temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
		arr[j + 1] = temp;
    }
    printf("\nSorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
	printf("\n");
}
