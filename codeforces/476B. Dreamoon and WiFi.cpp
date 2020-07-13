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

char str[100];

int main()
{
    int pos = 0;
    gets(str);
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == '-') pos--;
        else pos++;

    gets(str);
    int now = 0, q = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '?') q++;
        else if(str[i] == '-') now--;
        else now++;
    }
    int mov = pos-now;
    mov = abs(mov);
    if(q < mov)
    {
        puts("0.0");
        return 0;
    }
    int one = (q-mov)/2+mov;
    //printf("%d %d %d\n", mov, q, one);
    double ans = 1.000;
    for(int i = 1; i <= q; i++)
    {
        ans *= i;
    }
    for(int i = 1; i <= one; i++)
    {
        ans /= i;
    }
    for(int i = 1; i <= q-one; i++)
    {
        ans /= i;
    }
    //printf("%d %d\n", q, one);
    printf("%.12lf\n", (double) ans/(1<<q));
    return 0;
}


