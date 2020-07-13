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

bool func(int n)
{
    char str[50];
    sprintf(str,"%d", n);
    int len = strlen(str);
    len--;
    while(len>=0)
    {
        if(str[len] == '8') return true;
        len--;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i ; i++)
    {
        if(func(n+i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
