#include<stdio.h>

struct numbers { 
	unsigned int a;//bitfield condition
	unsigned int b;
};
int main()
{ 	
	struct numbers n;
	n.a = 3;
	n.b = 5;
	printf("a: %d, b: %d", n.a, n.b);
	return 0;
}
