#include<stdio.h>
int main()
{
    int multi_array[2][3][4];
    printf("sizeof multi_array[0][0][0]: %d\n", sizeof(multi_array[0][0][0]));
    printf("sizeof multi_array[0][0]: %d\n", sizeof(multi_array[0][0]));
    printf("sizeof multi_array[0]: %d\n", sizeof(multi_array[0]));
    printf("sizeof multi_array: %d\n", sizeof(multi_array));
    puts("");
    //
    printf("value of multi_array: %p\n", multi_array);
    printf("value of multi_array: %p\n", &multi_array[0]);
    printf("value of multi_array: %p\n", &multi_array[0][0]);
    printf("value of multi_array: %p\n", &multi_array[0][0][0]);
    return 0;
}