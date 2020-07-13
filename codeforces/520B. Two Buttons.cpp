#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

int flag[100000];
int n,m;

int func(void)
{
    queue<int> qu;
    flag[n] = 1;
    qu.push(n);
    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        if(x == m) return flag[m];
        if((x <= (m*3)) && flag[x<<1] == 0)
        {
            flag[x<<1] = flag[x]+1;
            qu.push(x<<1);
        }
        if(x > 0 && flag[x-1] == 0)
        {
            flag[x-1] = flag[x]+1;
            qu.push(x-1);
        }
    }
    return flag[m];
}

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", func()-1);
}
