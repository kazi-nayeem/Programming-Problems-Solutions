#include<cstdio>
using namespace std;

int main()
{
    int num[14];
    int t, flag = 0;
    int i, j, k, l, m, n;
    while(scanf("%d", &t) == 1)
    {
        if(t == 0) break;
        if(flag) putchar('\n');
        flag = 1;
        for(i = 0; i < t; i++)
            scanf("%d", &num[i]);
        for(i = 0; i < t; i++)
        {
            for(j = i + 1; j < t; j++)
            {
                for(k = j + 1; k < t; k++)
                {
                    for(l = k + 1; l < t; l++)
                    {
                        for(m = l + 1; m < t; m++)
                        {
                            for(n = m + 1; n < t; n++)
                            {
                                printf("%d %d %d %d %d %d\n", num[i], num[j], num[k], num[l], num[m], num[n]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
