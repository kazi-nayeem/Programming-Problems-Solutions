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
#define MX 205
#define pMX 20004

vector<int> adj[MX];
int match[MX], flag[MX], next[MX], now;
int prime[pMX];
int arr[MX];

void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i < pMX; i++)
    {
        if(prime[i] == 1) continue;
        for(int j = i*i; j < pMX; j+= i<<1)
            flag[j] = 1;
    }
}

int main()
{
    sieve();
    int n;
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(prime[arr[i]+arr[j]] == 0)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    memset(match,-1,sizeof match);
    for(int i = 1; i <= n; i++)
    {
        now++;
        if(!bpm(i,i))
        {
            puts("Impossible");
            return 0;
        }
    }
    return 0;
}

