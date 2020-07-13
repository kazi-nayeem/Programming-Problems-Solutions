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
using namespace std;

#define ll long long int
#define MX 1000000100
#define MAX 100000

int flag[MAX];
int pos;

void sieve(void);

bool prime(int n)
{
    if(n < 2) return false;
    int sq = sqrt(n)+1;
    for(int i = 0; i < pos && flag[i] < n; i++)
    {
        if(n % flag[i] == 0) return false;
    }
    return true;
}

int main()
{
    sieve();
    int n, a;
    scanf("%d", &n);
    //printf("%d\n", pos);
    for(int i = 0; i < pos &&  flag[i] < n; i++)
    {
        //printf("i %d\n", i);
        for(int j = 0; j < pos && (n > flag[j]+flag[i]); j++)
        {
            if(prime(n-flag[i]-flag[j]))
            {
                printf("3\n");
                printf("%d %d %d\n", flag[i], flag[j], n-flag[i]-flag[j]);
                return 0;
            }
        }
    }
    for(int i = 0; i < pos && n > flag[i]; i++)
    {
        if(prime(n-flag[i]))
        {
            printf("2\n");
            printf("%d %d\n", flag[i], n-flag[i]);
            return 0;
        }
    }
    if(prime(n))
    {
        printf("1\n%d\n", n);
        return 0;
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 2;
    pos = 1;
    long long int i, j, k;
    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            flag[pos++] = i;
            k = MAX / i;
            for(j = i; j <= k ; j += 2)
                flag[i * j] = 1;
        }
    }
    //for(int i = 0; i < 100; i++)
    //  printf("%d\n", flag[i]);
    //printf("pos %d\n", pos);
    return;
}




