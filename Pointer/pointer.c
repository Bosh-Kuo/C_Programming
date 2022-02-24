#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int i = 10;
    int j = 20;
    int *iptr = &i;
    printf("iptr = %p\n", iptr);
    printf("&iptr = %p\n", &iptr);
    printf("*iptr = %d\n", *iptr);
    printf("*(&iptr) = %p\n", *(&iptr));
    printf("&(*iptr) = %p\n", &(*iptr));
    printf("*(&(*iptr)) = %d\n", *(&(*iptr)));
    printf("*(*(&iptr)) = %d\n", *(*(&iptr)));
    printf("&(*(&iptr)) = %p\n", &(*(&iptr)));
    puts("\n");

    //Call by address(pointers)
    printf("Original i, j = %d, %d\n", i, j);
    swap(&i, &j);
    printf("Swapped i, j = %d, %d\n", i, j);


    return 0;
}