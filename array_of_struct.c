/*passing array of structures*/
#include<stdio.h>
struct student {
	char name[20] ;
	int roll;
	int marks;
};
void display(struct student);
void dec_marks(struct student s[]);
int main() 
{
	struct student s[3] = {
	{"rani", 101, 50}, {"vani", 102, 80}, {"veni", 103, 90} };
	dec_marks(s);
	for ( int i = 0; i < 3; i++)
	{
		display(s[i]);
	}
	return 0;
}
void dec_marks(struct student s[])
{
	for ( int i = 0; i < 3; i++)
	{
		s[i].marks = s[i].marks - 10;
	}
}
void display(struct student s)
{
	printf("Name:-%s ", s.name);
	printf("Roll:- %d ", s.roll);
	printf("Marks:- %d ", s.marks);
	printf("\n");
}
	

