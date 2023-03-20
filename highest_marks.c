/*structure to return the highest marks of students*/
#include<stdio.h>
#define SIZE 3
struct student { /*structure for student data*/
	char name[20];
	int roll;
	int marks[6];
	int total;
	char grade;
};
void display(struct student s);/*function prototype for disaplying contents of structure elements*/
void calculate( struct student s[]);/*function prototype for calculating the grade of students*/
void sort(struct student s[]);/*function prototype for sorting the names based on highest marks students scored*/
/*driven program*/
int main()
{
	struct student s[20], temp;
	for ( int i = 0; i < SIZE; i++)
	{
		printf("\nEnter student name:\n");
		scanf("%s", s[i].name);
		printf("\nEnter roll number:\n");
		scanf("%d", &s[i].roll);
		s[i].total = 0;
		printf("\nEnter marks of 3 subjects:\n");
		for ( int j = 0; j < SIZE; j++)
		{
			scanf("%d", &s[i].marks[j]);
		}	
	}
	calculate(s);
	sort(s);
	for ( int i = 0; i < SIZE;i++)
	{
		display(s[i]);
	}
	return 0;
}
void calculate(struct student s[]) /*calculating the grade of students uisng total subjscts marks*/
{
	for ( int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			s[i].total += s[i].marks[j];/*calculating the total marks*/
		}
		if ( s[i].total > 250)
			s[i].grade = 'A';
		else if ( s[i].total > 150 )
			s[i].grade = 'B';
		else 
			s[i].grade = 'C';
	}
}
void sort(struct student s[]) /*function to sort the order of names of students based on marks*/
{
	struct student temp;
	for ( int i = 0; i < SIZE -1;i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if ( s[i].total < s[j].total)/*checking with another index value if its less than the given if given enters the loop*/
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}	
void display(struct student s) /*function to display the entries*/
{
	printf("Name : %s ", s.name);
	printf("Roll:  %d ", s.roll);
	printf("Grade: %c ", s.grade);
	for ( int i = 0; i < SIZE; i++)
	{
		printf("\nsubject %d Marks:- %d ", i+1, s.marks[i]);
	}
	printf("\n");
}
