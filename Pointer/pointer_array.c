#include<stdio.h>
int *first_positive(int *ptr){
    while(*ptr <= 0)
        ptr++;
    return ptr;
}
int main(void)
{   
    int i;
    int array[] = {0,0,30,4,0,0,5,2};
    int *iptr;

    //Start from array[0]
    iptr = first_positive(array);
    printf("*iptr = %d\n", *iptr);
    printf("iptr - array = %d\n", iptr - array);

    //Start from array[4]
    iptr = first_positive(&array[4]);
    printf("*iptr = %d\n", *iptr);
    printf("iptr - array = %d\n", iptr - array);

    return 0;
}