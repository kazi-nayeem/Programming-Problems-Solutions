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

int power[20];

int getValue(int mask, int pos)
{
	return (mask/power[pos])%4;
}

int setValue(int mask, int pos, int val)
{
	return mask+((val-getValue(mask,pos))*power[pos]);
}

int dp[1<<22];
int n;

int func(int finalmask)
{
	queue<int> qu;
	qu.push(0);
	dp[0] = 0;
	while(!qu.empty())
	{
		int mask = qu.front();
		qu.pop();

		if(mask == finalmask) return dp[finalmask];
		int flag = 0;
		for(int i = 0; i < n; i++)
		{
            if((flag>>getValue(mask,i))&1) continue;
			flag |= (1<<getValue(mask,i));
			for(int j = 0; j < 4; j++)
			{
				if((flag>>j)&1) continue;
				int tem = setValue(mask,i,j);
				if(dp[tem] != -1) continue;
				dp[tem] = dp[mask]+1;
				qu.push(tem);
				//printf("%d %d\n", tem, mask);
			}
		}
	}
	return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	power[0] = 1;
	for(int i = 1; i < 12; i++)
		power[i] = power[i-1]*4;
	scanf("%d", &n);
	int mask = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		mask = setValue(mask,i,x-1);
	}
	//for(int i = 0; i < n; i++)
		//printf("%d\n", getValue(mask,i));
	memset(dp,-1,sizeof dp);
	printf("%d\n", func(mask));
    return 0;
}

