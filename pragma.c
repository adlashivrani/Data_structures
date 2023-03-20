#include<stdio.h>
//#pragma pack(1) 

struct emp {
	char a;
	int b;
//	char c;
//	int s;
	double d;
	char e;
};

int main()
{ 	
	printf("sizeof struct: %ld", sizeof(struct emp));
	return 0;
}
