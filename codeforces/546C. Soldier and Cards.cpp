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

queue<int> qu1;
queue<int> qu2;

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        qu1.push(x);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        qu2.push(x);
    }
    int i = 0;
    while(!qu1.empty() && !qu2.empty())
    {
        if(i > 3628800) break;
        i++;
        if(qu1.front() > qu2.front())
        {
            qu1.push(qu2.front());
            qu1.push(qu1.front());
        }
        else
        {
            qu2.push(qu1.front());
            qu2.push(qu2.front());
        }
        qu1.pop();
        qu2.pop();
    }
    if(qu1.empty())
    {
        printf("%d %d\n", i, 2);
    }
    else if(qu2.empty())
    {
        printf("%d %d\n", i, 1);
    }
    else
        puts("-1");
    return 0;
}

