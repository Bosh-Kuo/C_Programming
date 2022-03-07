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
  struct student john =
      {"John Smith", 12345, "1234567", {4.0, 3.9, 3.8, 3.6}, 2000, 1, 1};
  printf("name is %s\n", john.name);
  printf("id is %d\n", john.id);
  printf("phone is %s\n", john.phone);
  printf("grade is %f %f %f %f\n", john.grade[0],
         john.grade[1], john.grade[2], john.grade[3]);
  printf("birth_year is %d\n", john.birth_year);
  printf("birth_month is %d\n", john.birth_month);
  printf("birth_day is %d\n", john.birth_day);
  return 0;
}
