//#include <bits/stdc++.h>

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
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int flag[100];

bool func(int len1, char str1[], int len2, char str2[])
{
    memset(flag,0,sizeof flag);
    for(int i = 0; i < len1; i++)
        flag[str1[i]-'0'] = 1;
    for(int i = 0; i < len2; i++)
    {
        if(flag[str2[i]-'0'] == 0)
        {
            return false;
        }
    }
    return true;
}

int flag2[1000];

bool func2(int len1, char str1[], int len2, char str2[])
{
    memset(flag,0,sizeof flag);
    memset(flag2,0,sizeof flag2);
    for(int i = 0; i < len1; i++)
    {
        flag[str1[i]] = 1;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 100; i++)
    {
        cnt1 += flag[i];
        if(i <= '9' && i >= '0')
            flag2[i] = 1;
        else
            flag2[i] = 10000000;
    }
    int pos = -1;
    for(int i = 0; i < len2; i++)
    {
        if(flag[str2[i]] == 0)
        {
            if(pos == -1)
            {
                pos = i;
                i++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            cnt2 += flag2[str2[i]];
            flag2[str2[i]] = 0;
        }
    }
    //printf("%d %d\n", cnt1, cnt2);
    if(pos == -1)
    {
        if(cnt1 == cnt2)
            return true;
        for(int i = 0; i < len2; i++)
        {
            pos = i;
            if(pos>0)
            {
                if(flag[str2[pos]-1] != 0 && flag[str2[pos-1]+1] != 0)
                {
                    if(str2[pos-1]+1 == str2[pos]-1)
                    {
                        if((cnt2+flag2[str2[pos-1]+1]) == cnt1)
                            return true;
                    }
                    else if((cnt2+flag2[str2[pos-1]+1]+flag2[str2[pos]-1]) == cnt1)
                        return true;

                }
                if(flag[str2[pos]+1] != 0 && flag[str2[pos-1]-1] != 0)
                {
                    if(str2[pos-1]-1 == str2[pos]+1)
                    {
                        if((cnt2+flag2[str2[pos-1]-1]) == cnt1)
                            return true;
                    }
                    else if((cnt2+flag2[str2[pos-1]-1]+flag2[str2[pos]+1]) == cnt1)
                        return true;

                }
            }
        }
        return false;
    }
    if(pos>0)
    {
        if(flag[str2[pos]-1] != 0 && flag[str2[pos-1]+1] != 0)
        {
            if(str2[pos-1]+1 == str2[pos]-1)
            {
                if((cnt2+flag2[str2[pos-1]+1]) == cnt1)
                    return true;
            }
            else if((cnt2+flag2[str2[pos-1]+1]+flag2[str2[pos]-1]) == cnt1)
                return true;

        }
        if(flag[str2[pos]+1] != 0 && flag[str2[pos-1]-1] != 0)
        {
            if(str2[pos-1]-1 == str2[pos]+1)
            {
                if((cnt2+flag2[str2[pos-1]-1]) == cnt1)
                    return true;
            }
            else if((cnt2+flag2[str2[pos-1]-1]+flag2[str2[pos]+1]) == cnt1)
                return true;

        }
    }
    if(pos+1<len2)
    {
        pos++;
        if(pos>0)
        {
            if(flag[str2[pos]-1] != 0 && flag[str2[pos-1]+1] != 0)
            {
                if(str2[pos-1]+1 == str2[pos]-1)
                {
                    if((cnt2+flag2[str2[pos-1]+1]) == cnt1)
                        return true;
                }
                else if((cnt2+flag2[str2[pos-1]+1]+flag2[str2[pos]-1]) == cnt1)
                    return true;

            }
            if(flag[str2[pos]+1] != 0 && flag[str2[pos-1]-1] != 0)
            {
                if(str2[pos-1]-1 == str2[pos]+1)
                {
                    if((cnt2+flag2[str2[pos-1]-1]) == cnt1)
                        return true;
                }
                else if((cnt2+flag2[str2[pos-1]-1]+flag2[str2[pos]+1]) == cnt1)
                    return true;

            }
        }
    }
    return false;
}

char str1[10000];
char str2[10000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%s %s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        if(func(len1,str1,len2,str2) && func(len2,str2,len1,str1))
        {
            puts("friends");
            continue;
        }
        if(func2(len1,str1,len2,str2))
        {
            puts("almost friends");
            continue;
        }
        puts("nothing");

    }
    return 0;
}
/**
4
123 32331313323213
123 22121221
123 2223042
137 470
*/
