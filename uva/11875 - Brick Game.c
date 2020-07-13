#include<stdio.h>

int main()
{
    int t, i;
    int member[11];
    int n, nn;
    scanf(" %d", &t);
    for(i = 0; i < t;)
    {
        scanf(" %d", &n);
        for(nn = 0; nn < n ; ++nn)
        {
            scanf(" %d", &member[nn]);
        }
        printf("Case %d: %d\n", ++i, member[n/2]);
    }
    return 0;
}
