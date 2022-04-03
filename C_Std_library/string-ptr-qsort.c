#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define ZODIAC 12
#define STRLENGTH 80

// 要比較的元素是兩個指向字串的指標本身為(char*)， 指向這個元素的指標就是(char**)
int compare(const void *ptr1, const void *ptr2)
{
  return(strcmp(*((char**)ptr1), *((char**)ptr2)));
}
int main(void)
{
  char zodiac[ZODIAC][STRLENGTH];  // 字串陣列
  char *zodiac_ptr[ZODIAC];   // 字串指標陣列，每個元素都是一個指向字串的指標
  int i;
 
  for (i = 0; i < 12; i++) {
    zodiac_ptr[i] = zodiac[i];
    scanf("%s", zodiac[i]);
  }
 
  qsort(zodiac_ptr, ZODIAC, sizeof(char *), 
	compare);
  for (i = 0; i < ZODIAC; i++)
    puts(zodiac_ptr[i]);
  return 0;
}