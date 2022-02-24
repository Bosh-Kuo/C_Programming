#include <stdio.h>

int main(void)
{
    int integer;
    long int longInteger;
    short int shortInteger;
    long long int longLongInteger;

    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(long) = %lu\n", sizeof(long));
    printf("sizeof(short) = %lu\n", sizeof(short));
    printf("sizeof(long long) = %lu\n",
           sizeof(long long));
    return 0;
}