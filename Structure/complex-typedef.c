#include <stdio.h>
#include "complex.h"

 
void add_complex(Complex *a, Complex *b, Complex *c)
{
  c->real = a->real + b->real;
  c->imag = a->imag + b->imag;
  return;
}
void mul_complex(Complex *a, Complex *b, Complex *c)
{
  c->real = a->real * b->real - a->imag * b->imag;
  c->imag = a->real * b->imag + a->imag * b->real;
  return;
}
void print_complex(Complex *a)
{
  printf("%d+%di\n", a->real, a->imag);
  return;
}
 
int main(void)
{
  Complex a, b, c;
 
  scanf("%d", &(a.real));
  scanf("%d", &(a.imag));
  scanf("%d", &(b.real));
  scanf("%d", &(b.imag));
 
  add_complex(&a, &b, &c);
  print_complex(&c);
  mul_complex(&a, &b, &c);
  print_complex(&c);
  return 0;
}