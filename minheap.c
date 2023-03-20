#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

void swap(int*, int*);
void insert(int*, int);
void delete(int*, int);
void minheapify(int*, int, int);
void display(int*, int);
int size = 0;

int main()
{
        int arr[SIZE];
        int ch;
        int num;
        while (1) {
                printf("\nCHOOSE OPTION\n");
                printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("\nEnter data\n");
                                scanf("%d", &num);
                                insert(arr, num);
                                break;
                        case 2:
                                printf("\nEnter which data to delete\n");
                                scanf("%d", &num);
                                delete(arr, num);
                                break;
                        case 3:
                                display(arr, size);
                                break;
                        case 4:
                                exit(1);
                                break;
                        default:
                                printf("\nEnter Correct option\n");
                        }
        }
        return 0;
}

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void minheapify(int *arr, int size, int i)
{
        if ( size == 1) {
                printf("\nsingle element in the heap\n");
        }
        else {
                int largest = i;
                int left = (2*i);
                int right = (2*i) + 1;
                while ( left < size && arr[left] < arr[largest]) {
                        largest = left;
                }
                while ( right < size && arr[right] < arr[largest]) {
                        largest = right;
                }
                if ( largest != i) {
                        swap( &arr[largest], &arr[i]);
                        minheapify(arr, size, largest);
                }
        }
}

void insert( int *arr, int num)
{
        if ( size == 0) {
                arr[0] = num;
                size += 1;
        } else {
                arr[size] = num;
        size += 1;
                for (int i = size/2 - 1; i >= 0; i--) {
                        minheapify(arr, size, i);
                }
        }
}

void delete( int *arr, int num)
{
        int i;
        for ( i = 0; i < size; i++) {
                if ( arr[i] == num) {
                        break;
                }
        }
        swap( &arr[i], &arr[size -1] );
        size -= 1;
        for ( int i = size/2 - 1; i >= 0; i--) {
                minheapify(arr, size, i);
        }
}

void display(int *arr, int size)
{
        for ( int i = 0; i < size; i++) {
                printf(" %d-> ", arr[i]);
        }
}
