#include <stdio.h>
struct complex
{
    int real;
    int imag;
};

struct complex add_complex(struct complex a,
                           struct complex b)
{
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}
struct complex mul_complex(struct complex a,
                           struct complex b)
{
    struct complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}
void print_complex(struct complex a)
{
    printf("%d+%di\n", a.real, a.imag);
    return;
}

int main(void)
{
    struct complex a, b, c;

    scanf("%d", &(a.real));
    scanf("%d", &(a.imag));
    scanf("%d", &(b.real));
    scanf("%d", &(b.imag));

    c = add_complex(a, b);
    print_complex(c);
    c = mul_complex(a, b);
    print_complex(c);
    return 0;
}
