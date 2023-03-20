/*pointer to structure varibale*/
#include<stdio.h>
struct student {
	char name[20];
	int roll;
	int marks;
};
void display(struct student *);
void inc_marks(struct student *);
int main()
{
	struct student s1 = {"Rani", 101, 80};
	struct student s2 = { "Shiva", 102, 56};
	inc_marks(&s1);
	inc_marks(&s2);
	display(&s1);
	display(&s2);
	return 0;
}
void inc_marks( struct student *s)
{
	(s->marks)++;
}
void display(struct student *s)
{
	printf("Name -%s ", s->name);
	printf("Roll - %d ", s->roll);
	printf("Marks - %d ", s->marks);
	printf("\n");
}
	

