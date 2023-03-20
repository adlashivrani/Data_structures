#include<stdio.h>
#pragma pack(1)

struct emp {
        short int b;
        int c:23;
        char s;
        short d:10;
        short e:12;
};

int main()
{
        printf("sizeof struct: %ld", sizeof(struct emp));
        return 0;
}
