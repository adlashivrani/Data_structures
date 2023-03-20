#include<stdio.h>
int stack[100];
int choice;
int n;
int top;
int x;
int i;
void push(void);
void pop(void);
void display(void);
void peek(void);

int main()
{
    top = -1;
    printf("\nEnter the size of STACK [MAX = 100]: \n");
    scanf("%d", &n);
    printf("\nSTACK OPERATIONS USING ARRAY\n");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
    do	{
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
			case 4:
			{
				peek();
				break;
			}
            case 5:
            {
                printf("\nEXIT POINT\n");
                break;
            }
            default:
            {
                printf("\nPlease Enter a Valid Choice\n");
            }
                       }
    	} while (choice != 5);
    return 0;
}
void push()/*inserting elements into the stack*/
{
    if (top >= n - 1) {
        				printf("\nSTACK is over flow\n");
        
    		} else {
        				printf(" \nEnter a value to be pushed:\n");
        				scanf("%d", &x);
        				top++;
        				stack[top] = x;
    				}
}
void pop()/*deleteing the top most element from the stack*/
{
    if (top <= -1) {
        printf("\nStack is under flow\n");
    				} else {
        					printf("\nThe popped elements is %d\n", stack[top]);
        					top--;
    					   }
}
void peek()/*Displaying top of the stack*/
{
	if ( top == -1)
	{
		printf("\nstack is empty\n");
	} else {
				printf("\nStack top: %d\n", stack[top]);
			}
}  
void display()/*displaying stack elements*/
{
    if (top >= 0) {
        			printf("\nThe elements in STACK\n");
        			for (i = top; i >= 0; i--)
            		printf("\n%d", stack[i]);
    			  } else {
        					printf("\nThe STACK is empty\n");
    	   				 }
   
}
