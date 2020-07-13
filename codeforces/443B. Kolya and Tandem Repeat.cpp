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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char str[MX];

bool check(int tot, int add, int len)
{
    int n = tot/2;
    for(int i = 0; i+tot<=len+add; i++)
    {
        bool flag = true;
        for(int j = i; j < (i+n); j++)
        {
            //if(tot == 6)
              //  printf("%d %d\n", j, j+n);
            if(str[j] != str[j+n])
            {
                if(j+n<len)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
    }
    return false;
}

int main()
{
    gets(str);
    int len = strlen(str);
    int ad;
    scanf("%d", &ad);
    for(int i = ((len+ad)/2) * 2; i > 0; i-=2)
    {
        //printf("%d\n", i);
        if(check(i,ad,len))
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}


