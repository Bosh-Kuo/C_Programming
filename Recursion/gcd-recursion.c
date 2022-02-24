#include <stdio.h>

int gcd(i, j)
{
    int big, small;
    if (i >= j)
    {
        big = i;
        small = j;
    }
    else
    {
        big = j;
        small = i;
    }

    if (big % small == 0)
        return small;
    return (gcd(small, (big % small)));
}

int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    printf("gcd(%d, %d) = %d\n", i, j, gcd(i, j));
}