#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long

#define MX 1005

int flag[MX];

int main()
{
    for(int i = 2; i < MX; i++)
    {
        int ad = i*i;
        for(int j = ad; j < MX; j+= ad)
            flag[j] = 1;
        if(flag[i]) continue;
        for(int j = i-1; j > 0; j--)
        {
            if(flag[j] == 1 && flag[i-j] == 1)
            {
                flag[i] = 1;
                break;
            }
        }
    }
    for(int i = 1; i < MX; i++)
        flag[i] += flag[i-1];
    ll int te, ti, a, b, res1, res2;
    scanf("%lld", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &a, &b);
        if(a <= 1000)
            res1 = flag[a-1];
        else
            res1 = a-1 + flag[1000]-1000;
        if(b <= 1000)
            res2 = flag[b];
        else
            res2 = b+flag[1000]-1000;
        printf("%lld\n", res2-res1);
    }
    return 0;
}

