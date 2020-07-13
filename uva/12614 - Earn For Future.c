#include<stdio.h>

int main()
{
    int t, count;
    int n;
    register int i, flag;
    long long int card[31];
    register long long int max;
    scanf(" %d", &t);
    for(count = 0; count < t;)
    {
        scanf("%d", &n);
        for(max = i = 0; i < n; ++i)
        {
            scanf(" %lld", &card[i]);
            if(max < card[i])
            {
                max = card[i];
                flag = i;
            }
        }
        for(i = 0; i < n; ++i)
        {
            if(flag != i)
            {
                if(max <  (card[flag] & card[i]))
                max = card[flag] & card[i];
            }
        }
        printf("Case %d: %lld\n", ++count, max);
    }
    return 0;
}
