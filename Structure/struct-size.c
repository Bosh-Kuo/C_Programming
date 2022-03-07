#include <stdio.h>
struct student
{
  char name[20];
  int id;
  char phone[10];
  float grade[4];
  int birth_year;
  int birth_month;
  int birth_day;
};
int main(void)
{
  struct student john;
  printf("sizeof(john) = %lu\n", sizeof(john));
  return 0;
}