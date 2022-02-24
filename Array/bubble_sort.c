#include<stdio.h>
int main()
{
    int array[] = {4,3,1,7,3,8,10,35,2,52};  //未照順序排列
    int arrayLength = sizeof(array)/sizeof(array[0]);
    int i, j, temp;
    printf("Length of of the array is: %d\n",arrayLength);  // 陣列長 = 陣列大小 / 陣列元素大小
    // print unsorted array
    for (i = 0; i < arrayLength;  i++){
        printf("%d\n", array[i]);
    }
    puts("");

    // bubble sort
    for (int i = arrayLength-2; i >= 0; i--)
        for(j = 0; j <= i; j++)
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

    // print sorted array
    for (i = 0; i < arrayLength;  i++){
        printf("%d\n", array[i]);
    }
    return 0;

}