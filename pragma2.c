#include<stdio.h>
#pragma pack(1)

struct emp {
        char a:2;
        char c:3;
        char s:5;
        char e;
};

int main()
{
        printf("sizeof struct: %ld", sizeof(struct emp));
        return 0;
}
