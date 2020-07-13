#include <bits/stdc++.h>

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

char one[20][10] = {"zero","one","two","three","four","five","six","seven","eight","nine",
                    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                    "eighteen","nineteen"
                   };
char ten[10][10] = {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main()
{
    while(true)
    {
        int a;
        scanf("%d", &a);
        if(a < 20) puts(one[a]);
        else
        {
            printf("%s", ten[a/10]);
            if(a%10)
                printf("-%s", one[a%10]);
            puts("");
        }
        return 0;
    }
    return 0;
}
