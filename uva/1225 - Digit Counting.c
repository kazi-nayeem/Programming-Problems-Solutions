#include<stdio.h>
#define MAX 10001
int main()
{
    int number[MAX][10];
    int i, j;
    int n, m;
    for(i = 0; i < 10; i++)
        number[0][i] = 0;
    for(i = 1; i < MAX; i++)
    {
        n = i;
        for(j = 0; j < 10; j++)
            number[i][j] = number[i-1][j];
        for(;n > 0; n /= 10)
            number[i][n%10]++;
    }
    scanf("%d", &i);
    while(i--)
    {
        scanf("%d", &n);
        printf("%d %d %d %d %d %d %d %d %d %d\n", number[n][0], number[n][1], number[n][2], number[n][3], number[n][4], number[n][5], number[n][6], number[n][7], number[n][8], number[n][9]);
    }
    return 0;
}
