#include <stdio.h>

void hanoi(int n, char buffer, char src, char dst)
{
    // 印出此輪的 buffer, src, dst
    printf("hanoi(%d, %c, %c, %c)\n", n,
           buffer, src, dst);
    if (n == 1)
        printf("Move disk from %c to %c\n", src, dst);
    else
    {
        // 將目標柱先當緩衝，將上面的n-1個石盤移到原本的緩衝
        hanoi(n - 1, dst, src, buffer);
        // 將最底的石盤從src移到dst
        printf("move disk from %c to %c\n", src, dst);
        // 將剛剛移到緩衝的n-1個石盤以原本的src當作緩衝一到dst
        hanoi(n - 1, src, buffer, dst);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'B', 'A', 'C');
}