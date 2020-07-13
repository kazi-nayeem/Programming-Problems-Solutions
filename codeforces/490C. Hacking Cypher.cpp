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

char str[1000005];
ll res[1000005];

int main()
{
    gets(str);
    int a, b;
    scanf("%d%d", &a, &b);
    ll sum = 0, tem = 1;
    int len = strlen(str);
    for(int i = len-1; i >= 0; i--)
    {
        sum += (str[i]-'0')*tem;
        sum %= b;
        res[i] = sum;
        tem *= 10;
        tem %= b;
    }
    ll mod = sum, sum2, pos = -1;
    sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum *= 10;
        sum += str[i]-'0';
        sum %= a;
        if((sum == 0) && (i + 1< len) && (res[i+1] == 0)  && (str[i+1] != '0'))
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    char ch = str[pos+1];
    str[pos+1] = 0;
    puts(str);
    str[pos+1] = ch;
    puts(str+pos+1);
    return 0;
}

