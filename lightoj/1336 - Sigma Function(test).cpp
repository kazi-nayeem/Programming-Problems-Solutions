#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        int res = 0;
        for(int i = 2; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= i; j++)
                if(i % j == 0)
                    sum += j;
            if(sum%2 == 0)
            {
                res++;
                /*printf("%d ", i);
                int k = i;
                for(int j = 2; j <= k; j++)
                {
                    int t = 0;
                    while(k%j == 0)
                    {
                        t++;
                        k/=j;
                    }
                    if(t)
                        printf(" %d(%d)", j, t);
                }
                puts("");*/
            }
        }
        printf("%d %d\n", res, n-res);
    }
    return 0;
}

