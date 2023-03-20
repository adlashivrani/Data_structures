/* Simple Binary Search Program Using Functions in C*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

void binary_search(int[], int);

int main() {
    int arr_search[MAX_SIZE];
	int i;
	int element;
    printf("\nEnter %d Elements for Searching : \n", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++)
        scanf("%d", &arr_search[i]);
	printf("\nEnter Element to Search : \n");
    scanf("%d", &element);
    binary_search(arr_search, element);
}

void binary_search(int fn_arr[], int element)
{
    int first = 0;
	int last = MAX_SIZE;
	int mid;
    while (first <= last) {
	  		mid = (first+last)/2;
	  		if (fn_arr[mid] == element) {
         		printf("\nSearch Element  : %d  : Found :  Position : %d.\n", element, mid + 1);
         		break;
      		} else if (fn_arr[mid] < element) {
         		first = mid + 1;    
      		} else {
         		last = mid - 1;
			}
   }
   if (first > last)
      printf("\nSearch Element : %d  : Not Found \n", element);
}
