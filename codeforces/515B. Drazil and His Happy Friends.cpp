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

int flagboy[105];
int flaggir[105];

int main()
{
    int boy, girl, hb, hg, x;
    scanf("%d%d", &boy, &girl);
    scanf("%d", &hb);
    for(int i = 0; i < hb; i++)
    {
        scanf("%d", &x);
        flagboy[x] = 1;
    }
    scanf("%d", &hg);
    for(int i = 0; i < hg; i++)
    {
        scanf("%d", &x);
        flaggir[x] = 1;
    }
    for(int i = 0; i <= 1000000; i++)
    {

        if(flaggir[i%girl] == 1)
        {
            flagboy[i%boy] = 1;
        }
        else if(flagboy[i%boy] == 1)
        {
            flaggir[i%girl] = 1;
        }
    }
    x = 0;
    for(int i = 0; i < boy; i++) x += flagboy[i];
    for(int i = 0; i < girl; i++) x += flaggir[i];
    if(x == boy+girl)
        puts("Yes");
    else
        puts("No");
    return 0;
}
