#include <stdio.h>
struct complex
{
    int real;
    int imag;
};

void add_complex(const struct complex *a,
                 const struct complex *b, struct complex *c)
{
    c->real = a->real + b->real;
    c->imag = a->imag + b->imag;
    return;
}

void mul_complex(const struct complex *a,
                 const struct complex *b, struct complex *c)
{
    c->real =
        a->real * b->real - a->imag * b->imag;
    c->imag =
        a->real * b->imag + a->imag * b->real;
    return;
}

void print_complex(const struct complex *a)
{
    printf("%d+%di\n", a->real, a->imag);
    return;
}

int main(void)
{
    struct complex a, b, c;

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