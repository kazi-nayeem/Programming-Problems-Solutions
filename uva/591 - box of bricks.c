#include<stdio.h>

int main()
{
    long int n, h[50], a, i, j = 0;
    long int sum;
    while(scanf(" %ld", &n) == 1)
    {
        if(n == 0) break;
        for(sum = 0,i = 0; i < n ; i++)
        {
            scanf(" %ld", &h[i]);
            sum += h[i];
        }
        a = sum/n;
        for(sum = 0, i = 0; i < n; ++i)
            if(a > h[i])
                sum += a - h[i];
        printf("Set #%ld\nThe minimum number of moves is %ld.\n\n",++j, sum);
    }
    return 0;
}
