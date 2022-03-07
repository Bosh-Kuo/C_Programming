#include <stdio.h>
#include <string.h>
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
  struct student *ptr = &john;
  strcpy(ptr->name, "John Smith");
  ptr->id = 12345;
  strcpy(ptr->phone, "1234567");
  ptr->grade[0] = 4.0;
  ptr->grade[1] = 3.9;
  ptr->grade[2] = 3.8;
  ptr->grade[3] = 3.6;
  ptr->birth_year = 2000;
  ptr->birth_month = 1;
  ptr->birth_day = 1;
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
