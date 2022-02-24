q#include <stdio.h>

int main()
{   
    
    int array[5];
    int zero[10] = {0}; //初始化
    int i;
    //array memory and address
    printf("sizeof of the array[0] is: %d\n",sizeof(array[0]));
    printf("sizeof of the array is: %d\n", (int) sizeof(array) );  //陣列大小
    printf("sizeof of the array is: %d\n", (int) (sizeof(array)/sizeof(array[0])) );  // 陣列長 = 陣列大小 / 陣列元素大小
    for (i=0; i<5; i++){
        printf("%p\n", &array[i]);
    }
    printf("address of array is: %p\n",&array);
    printf("value of array is: %p\n",array);

    
    // array input & output
    printf("key in 5 integer:");
    for (i=0; i<5; i++)
        scanf("%d", &(array[i]));

    puts(" ");
    for (i=0; i<5; i++)
        printf("%d\n", array[i]);
    return 0;
}