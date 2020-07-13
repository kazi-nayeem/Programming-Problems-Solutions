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
#include<complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 300005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int xaxis[MX];
int yaxis[MX];
int res[MX];
char str[MX];
char str2[MX];

void add(char ch, int &diffx, int &diffy)
{
    if (ch == 'U')
        diffy--;
    else if (ch == 'D')
        diffy++;
    else  if (ch == 'R')
        diffx--;
    else if (ch == 'L')
        diffx++;
}

void remov(char ch, int &diffx, int &diffy)
{
    if (ch == 'U')
        diffy++;
    else if (ch == 'D')
        diffy--;
    else  if (ch == 'R')
        diffx++;
    else if (ch == 'L')
        diffx--;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x, y;
    scanf("%d %s %d %d", &n, str, &x, &y);
    if (n<(abs(x)+abs(y)))
    {
        printf("-1\n");
        return 0;
    }
    if ((n-(abs(x)+abs(y)))%2 == 1)
    {
        printf("-1\n");
        return 0;
    }
    int totalx = 0, totaly = 0;
    for(int i = 0; i < n; i++)
    {
        if (str[i] == 'U')
            yaxis[i]++;
        else if (str[i] == 'D')
            yaxis[i]--;
        else  if (str[i] == 'R')
            xaxis[i]++;
        else if (str[i] == 'L')
            xaxis[i]--;
        totalx += xaxis[i];
        totaly += yaxis[i];
        str2[i] = str[i];
    }
    int diffx = x-totalx;
    int diffy = y-totaly;
    int last = 0;
    int ans = n*2;
    if (diffx != 0 || diffy != 0)
    {
        for(int i = 0; i < n; i++)
        {
            last = max(last,i);
            for(; last<n && (diffx != 0 || diffy != 0); last++)
            {
                if (str[last] == 'U') {
                    if(diffy>0) continue;
                } else if (str[last] == 'D') {
                    if(diffy<0) continue;
                } else if (str[last] == 'L') {
                    if(diffx<0) continue;
                } else if (str[last] == 'R') {
                    if(diffx>0) continue;
                }

                remov(str[last],diffx,diffy);

                if (diffx<0)
                {
                    str[last] = 'L';
                }
                else if (diffx>0)
                {
                    str[last] = 'R';
                }
                else if (diffy<0)
                {
                    str[last] = 'D';
                }
                else if (diffy>0)
                {
                    str[last] = 'U';
                }

                add(str[last],diffx,diffy);
            }
            if (diffx == 0 && diffy == 0)
            {
                ans = min(ans,last-i);
            }

            remov(str[i],diffx,diffy);

            str[i] = str2[i];

            add(str[i],diffx,diffy);

        }
    } else {
        ans = 0;
    }
    if(ans == 2*n) ans = -1;
    printf("%d\n", ans);
    return 0;
}

