#include <stdio.h>

int fib(int i)
{
    if (i == 1 || i == 0)
        return i;
    return fib(i - 1) + fib(i - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("fib(%d) = %d\n", n, fib(n));
}