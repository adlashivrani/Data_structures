#include<stdio.h>

typedef union  name {
        char sname[10];
        int age;
        int salary;
} name;
//typedef union name name;

int main()
{
    name n;
    printf("Enter Name:\n");
    scanf("%s", n.sname);
	printf("Name: %s\n", n.sname);
	printf("Enter age: \n");
	scanf("%d", &n.age);
	printf("Age: %d\n", n.age);
	printf("Enter Salary: \n");
	scanf("%d", &n.salary);
	printf("Salary: %d\n", n.salary);
    // printf("%s %d %d", n.sname, n.age, n.salary); 
	/*It does not work because union takes one member at once 
	for that we have to take one element at a time */
    return 0;
}
