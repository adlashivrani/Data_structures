/*program to understand how a structure varibale used as function argument*/
#include<stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
	};
void display(struct student);
int main()
{
	struct student std1 = {"rani", 505, 90};
	struct student std2 =  {"Shivani", 507, 78};
	display(std1);
	display(std2);
	return 0;
}
void display( struct student std)
{
	printf("Name: - %s ", std.name);
	printf("Rollno:- %d ", std.rollno);
	printf("Marks:- %d ", std.marks);
	printf("\n");
}
	
