#include<stdio.h>

typedef struct  name {
	char sname[10];
	int age;
	int salary;
} name;
//typedef struct name name;

int main() 
{ 	
	name n;
	printf("Enter Name, age, salary:\n");
	scanf("%s %d %d", n.sname, &n.age, &n.salary);
	printf("%s %d %d", n.sname, n.age, n.salary);
	return 0;
}
