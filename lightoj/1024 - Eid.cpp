#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 10010
#define MX2 1230

int prime[MX2];
int flag[MX];
int pos[MX];
int arr[MX2];

void sieve(void)
{
    flag[1] = 5;
    prime[0] = 2;
    pos[2] = 0;
    int n = 1;
    for(int i = 2; i < MX; i+=2)
        flag[i] = 2;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            pos[i] = n;
            prime[n] = i;
            n++;
            for(int j = i; j < MX; j += i)
                flag[j] = i;
        }
    }
    //printf("%d\n", n);
    //for(int i = MX2-17; i < MX2; i++)
    // printf("i%d prime%d pos%d flag%d\n", i, prime[i], pos[prime[i]], flag[prime[i]]);
    return;
}

int main()
{
    char str[MX];
    sieve();
    int te, ti, n, tm, k, p;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        memset(arr,0,sizeof arr);
        for(int i = 0; i < n; i++)
        {
            scanf(" %d", &tm);
            while(tm > 1)
            {
                p = flag[tm];
                k = 0;
                while(tm%p == 0)
                {
                    k++;
                    tm /= p;
                }
                arr[pos[p]] = max(arr[pos[p]],k);
            }
        }
        memset(str,0,sizeof str);
        str[0] = 1;
        for(int i = 0; i < MX2; i++)
        {
            if(arr[i] > 0)
            {
                //printf("%d %d\n", prime[i], arr[i]);
                int multi = 1;
                for(int j = 0; j < arr[i]; j++) multi *= prime[i];
                int cary = 0, tot;
                for(int j = 0; j < 4000; j++)
                {
                    tot = str[j]*multi+cary;
                    str[j] = tot%10;
                    cary = tot/10;
                }
            }
        }
        printf("Case %d: ", te);
        for(int i = 4000-1; i >=0; i--)
        {
            if(str[i] > 0)
            {
                for(; i>=0; i--)
                    putchar(str[i]+'0');
            }
        }
        putchar('\n');
    }
    return 0;
}
