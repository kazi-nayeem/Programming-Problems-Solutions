#include<stdio.h>

int main()
{
    int i, j, k, l;
    int n, m, test = 1;
    long long int sum;
    int arr[11][11];
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
        printf("Case %d:", test++);
        m = (n + 1) / 2;
        for(i = 0; i < m; i++)
        {
            sum = 0;
            l = n - i;
            for(j = i; j < l; j++)
            {
                sum += arr[j][i];
                k = l - 1;
                if(k != i)
                    sum += arr[j][k];
            }
            k = n - i - 1;
            for(j = i + 1; j < k; j++)
            {
                sum += arr[i][j];
                if(i != k)
                    sum += arr[k][j];
            }
            printf(" %lld", sum);
        }
        putchar('\n');
    }
    return 0;
}
