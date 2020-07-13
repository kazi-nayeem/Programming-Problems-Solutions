#include<cstdio>
#include<iostream>
using namespace std;

#define ll long long
#define MX 1000050

int mob[MX];
bool col[MX];

void mobious(void);

int main()
{
    mobious();
    //for(int i = 0; i < 26; i++)
       // printf("%3d %3d\n", i, mob[i]);

    ll res, a, b, m;
    int te, ti;

    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &a, &b);
        res = 0;
        m = min(a, b);
        for(ll i = 1; i <= m; i++)
            res += mob[i]*(a/i)*(b/i);
        printf("Case %d: %lld\n", te, res+2);
    }
}

void mobious(void)
{
    for(ll i = 1; i < MX; i++) mob[i] = 1;
    for(ll i = 2; i < MX; i++)
        if(!col[i])
    {
        mob[i] = -1;
        for(ll j = i*2;j<MX;j+=i)
        {
            col[j] = true;
            if(j%(i*i) == 0) mob[j] = 0;
            else
                mob[j] *= (-1);
        }
    }
    return;
}
