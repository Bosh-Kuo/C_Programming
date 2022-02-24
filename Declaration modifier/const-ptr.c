#include <stdio.h>
int main(void)
{
    int i = 1;
    int j = 2;
    int *ptr_to_int = &i;
    const int *ptr_to_const_int = &i;
    int *const const_ptr_to_int = &i;
    const int *const const_ptr_to_const_int = &i;
    ptr_to_int = &j;              /* OK */
    *ptr_to_int += 3;             /* OK */
    ptr_to_const_int = &j;        /* OK */
    *ptr_to_const_int += 3;       /* not OK */
    const_ptr_to_int = &j;        /* not OK */
    *const_ptr_to_int += 3;       /* OK */
    const_ptr_to_const_int = &j;  /* not OK */
    *const_ptr_to_const_int += 3; /* not OK */
    return 0;
}