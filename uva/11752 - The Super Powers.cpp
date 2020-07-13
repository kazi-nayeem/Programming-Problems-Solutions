#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long
#define MAX (1<<16)

short int flag[MAX];

vector<unsigned ll> vc;



void sieve(void)
{
    flag[0] = 1, flag[1] = 1;
    long int i, j, k;
    for(i = 4; i <= MAX; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            k = MAX / i;
            for(j = i; j <= k ; j += 2)
                flag[i * j] = 1;
        }
    }
    return;
}

int main()
{
    unsigned ll int re = 1<<16;
    for(unsigned ll int i = 1; i < re; i++)
        vc.push_back((unsigned ll) i*i*i*i);
    sort(vc.begin(),vc.end());
    for(int i = 0; i < 100; i++)
        printf("%llu\n", vc[i]);
    return 0;
}

