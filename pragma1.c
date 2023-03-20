#include<stdio.h>
 #pragma pack(1)

struct emp {
        char a;
        short int b:12;
        char c;
        int s:20;
        short int d;
        char e:2;
};

int main()
{
        printf("sizeof struct: %ld", sizeof(struct emp));
        return 0;
}
