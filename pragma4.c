#include<stdio.h>
#pragma pack(1)

struct emp {
	int a:17;
	short b:12;
	int c:7;
    char d:4;
    short s:12;
    char f:4;
	int n:12;
    char e;
};

int main()
{
        printf("sizeof struct: %ld", sizeof(struct emp));
        return 0;
}
