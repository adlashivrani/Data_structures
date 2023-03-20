#include<stdio.h>
void bubble_sort(int *, int);
int main() {
    int arr[50];
	int num;
	int x;    
    printf("enter the number of elements to insert: ");
    scanf("%d", &num);    
    printf("enter the values:");
    for (x = 0; x < num; x++)
        scanf("%d", &arr[x]);
	bubble_sort(arr, num);
	return 0;
}
void bubble_sort(int arr[], int num)
{
	int x;
	int y;
	int temp;
	int flag;
    for (x = 0; x < num - 1; x++) { 
		flag = 0;      
        for(y = 0; y < num - x - 1; y++) {          
            if (arr[y] > arr[y + 1]) {               
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
				flag = 1;
            }
        }
		if (flag == 0)
			break;
    }
    printf("\nArray after implementing bubble sort: \n");
    for (x = 0; x < num; x++) {
        printf("%d  ", arr[x]);
    }
	printf("\n");
}
