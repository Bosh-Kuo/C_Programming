#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define STRLENGTH 80
#define ZODIAC 12
 
// 要比較的元素是兩個長度為 STRLENGTH 的字串， ptr1 為字串1的位址，ptr2 為字串2的位址
int compare(const void *ptr1, const void *ptr2)
{
  return(strcmp((char *) ptr1, (char *) ptr2));
}
int main(void)
{
  char zodiac[ZODIAC][STRLENGTH];  
  int i;
 
  for (i = 0; i < ZODIAC; i++)
    scanf("%s", zodiac[i]);
 
  qsort(zodiac, ZODIAC, sizeof(char) * STRLENGTH, 
	compare);
 
  for (i = 0; i < ZODIAC; i++)
    puts(zodiac[i]);
 
  return 0;
}