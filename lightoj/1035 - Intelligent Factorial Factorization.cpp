#include<cstdio>
#include<cstring>
using namespace std;

int prime[25], flag[101], ans[101][25];

void sieve(void)
{
    prime[0] = 2;
    int pos = 1;
    for(int i = 3; i < 98; i+=2)
    {
        if(flag[i] == 1) continue;
        prime[pos++] = i;
        int add = i << 1;
        for(int j = i * i; j < 98; j += add) flag[j] = 1;
    }
    //printf("%d\n", pos);
    //for(int i = 0; i < pos; i++) printf("%d\n", prime[i]);
    for(int i = 2; i < 101; i++)
    {
        for(int j = 0; j < 25; j++) ans[i][j] = ans[i-1][j];
        int n = i;
        for(int j = 0; j < 25 && n != 1;)
        {
            if(n%prime[j] == 0)
            {
                ans[i][j]++;
                n/=prime[j];
            }
            else j++;
        }
    }
    return;
}

int main()
{
    sieve();
    int n , te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        printf("Case %d: %d = 2 (%d)", te, n, ans[n][0]);
        for(int i = 1; i < 25; i++)
        {
            if(ans[n][i] == 0) break;
            printf(" * %d (%d)", prime[i], ans[n][i]);
        }
        putchar('\n');
    }
    return 0;
}
