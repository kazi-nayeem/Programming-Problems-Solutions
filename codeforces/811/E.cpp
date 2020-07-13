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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

#define block 2

struct data{
    int l, r, pos;
    bool operator < (const data & p) const
    {
        if(l/block == p.l/block) return r < p.r;
        return l/block <= p.l/block;
    }
};

int ans[MX];
int arr[12][MX];
data query[MX];

int answer;
int n, m, q;

void add(int pos, int flag)
{
    //printf("add %d %d\n", pos, flag);
    for(int i = 1; i <= n; i++)
    {
        answer++;
        if(arr[i][pos] == arr[i-1][pos])
        {
            answer--;
        }
        if(flag == 1 && arr[i][pos+1] == arr[i][pos])
        {
            answer--;
        }else if(flag == 2 && arr[i][pos-1] == arr[i][pos])
        {
            answer--;
        }
    }
    printf("add %d %d ans %d\n", pos, flag, answer);
}

void remove(int pos, int flag)
{

    for(int i = 1; i <= n; i++)
    {
        answer--;
        if(arr[i][pos] == arr[i-1][pos])
        {
            answer++;
        }else if(flag == 1 && arr[i][pos+1] == arr[i][pos])
        {
            answer++;
        }else if(flag == 2 && arr[i][pos-1] == arr[i][pos])
        {
            answer++;
        }
    }
    printf("rem %d %d ans %d\n", pos, flag, answer);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);
    puts("ok");
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &query[i].l, &query[i].r);
        query[i].pos = i;
    }
    sort(query,query+q);
    for(int i = 0; i < q; i++)
    {
        printf("%d %d %d\n", query[i].l, query[i].r, query[i].pos);
    }
    int currentL = 1, currentR = 1;
    answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i][1] != arr[i-1][1]) answer++;
    }
    printf("ans %d\n", answer);
	for(int i=0; i<q; i++) {
		int L = query[i].l, R = query[i].r;
		while(currentL > L) {
			add(currentL-1,1);
			currentL--;
		}
		while(currentR < R) {
			add(currentR+1,2);
			currentR++;
		}
		while(currentL < L) {
			remove(currentL,1);
			currentL++;
		}
		while(currentR > R) {
			remove(currentR,2);
			currentR--;
		}
		ans[query[i].pos] = answer;
		printf("%d %d %d %d\n", query[i].l, query[i].r, query[i].pos, answer);
	}
	for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
    return 0;
}


