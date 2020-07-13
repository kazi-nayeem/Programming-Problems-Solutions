#include<stdio.h>

int main()
{
    int n, i, k, maxi, mini, test;
    scanf("%d", &test);
    while(test--)
    {
        maxi = 0;
        mini = 102;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &k);

            if(mini > k)
                mini = k;
            if(maxi < k)
                maxi = k;
        }
        printf("%d\n", (maxi - mini)<<1);
    }
    return 0;
}
