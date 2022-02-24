#include <stdio.h>
#include <stdlib.h>
void place_queen(int i, int queen_pos[8])
{
    int j, k, conflict;

    for (k = 0; k < i; k++)
        printf("%d ", queen_pos[k]);
    printf("\n");

    if (i == 8)
        exit(0);

    for (k = 0; k < 8; k++)
    {
        // k 為要試的列
        conflict = 0;
        for (j = 0; j < i && !conflict; j++)
            // 若第i行以前的皇后跟第i行要放置的列k相同或是
            if (queen_pos[j] == k || abs(k - queen_pos[j]) == (i - j))
                conflict = 1;
        if (!conflict)
        {
            queen_pos[i] = k;
            place_queen(i + 1, queen_pos);
        }
    }
}
int main(void)
{
    int queen_pos[8];
    place_queen(0, queen_pos);
    return 0;
}