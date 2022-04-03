#include <stdio.h>
#include <stdlib.h>
 
int compare(const void *data1, const void *data2)
{
  int *ptr1 = (int *)data1;  //指標轉型
  int *ptr2 = (int *)data2;  //指標轉型
  if (*ptr1 > *ptr2)
    return -1;
  else if (*ptr1 < *ptr2)
    return 1;
  else
    return 0;
}
#define ARRAYSIZE 10
 
int main(void)
{
  int i;
  int array[ARRAYSIZE];
 
  for (i = 0; i < 10; i++)
    scanf("%d", &(array[i]));
  qsort(array, ARRAYSIZE, sizeof(int), compare);
  for (i = 0; i < ARRAYSIZE; i++)
    printf("%d ", array[i]);
  return 0;
}
