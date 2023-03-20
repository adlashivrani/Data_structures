/*  C Program to implement Merge Sort using Recursion  */
#include <stdio.h>
void mergeSort(int [], int, int, int);
void partition(int [], int, int);
int main()
{
    int list[50];
    int i;
	int size;
    printf("How Many elements u want to Sort :: ");
    scanf("%d", &size);
    printf("\nEnter [ %d ] elements below to be Sorted : \n",size);
    for(i = 0; i < size; i++)
    {
         printf("\nEnter [ %d ] Element : ",i+1);
         scanf("%d", &list[i]);
    }
    partition(list, 0, size - 1);
    printf("\n\nAfter implementing Merge sort, Sorted List is : \n\n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ", list[i]);
    }
    printf("\n");
    return 0;
}
void partition(int list[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);//left recursion
        partition(list, mid + 1, high);//right recursion
        mergeSort(list, low, mid, high);//merging of two sorted sub arrays
    }
}
void mergeSort(int list[],int low,int mid,int high)
{
    int i;
    int j;
    int k;
	int lo;
    i = low;
	lo = low;
    j = mid + 1;
	int temp[50];//temp array for merging lists
    while ((lo <= mid) && (j <= high))//while elements in both the list
    {
        if (list[lo] <= list[j])
        {
            temp[i] = list[lo];
            lo++;
        }
        else
        {
            temp[i] = list[j];
            j++;
        }
        i++;
    }
    if (lo > mid)//copy remaining elements of the first list 
    {
        for (k = j; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else//copy remaining elements of the second list
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }
	//transfer elements from temp[] back to list[]
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}
