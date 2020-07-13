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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX];

void print(int s, int e)
{
    if(s>e) return;
    for(int i = s; i < e; i++)
    {
        printf("%c->", arr[i]+'0');
    }
    printf("%c", arr[e]+'0');
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    if(arr[n] == 1)
    {
        puts("NO");
        return 0;
    }
    if(n == 1 || arr[n-1] == 1)
    {
        puts("YES");
        print(1,n);
        return 0;
    }
    int pos = n-2;
    while(arr[pos] == 1) pos--;
    if(pos == 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    print(1,pos-1);
    if(pos == n-2)
    {
        if(n>3) printf("->");
        printf("(0->0)->0");
        return 0;
    }
    if(pos>1) printf("->");
    printf("(0->(");
    print(pos+1,n-1);
    printf("))->0");
    return 0;
}


