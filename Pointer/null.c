#include<stdio.h>
int main(void)
{
    int *ptr;
    ptr = NULL;
    printf("%p\n", ptr);
    printf("%p\n", &ptr);
    //printf("%p\n", *ptr);  //會出錯，NULL不存放任何數值
    return 0;
}