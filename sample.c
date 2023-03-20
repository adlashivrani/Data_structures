#include<stdio.h>
struct student {
	char name[20];
	int roll;
	int marks;
};
void main()
{
	struct student s1 = { "rani", 101, 90};
	struct student s2 = { "shivani", 102, 98};
	printf("%s %d %d \n", s1.name, s1.roll, s1.marks);
	printf("%s %d %d \n", s2.name, s2.roll, s2.marks);
}
