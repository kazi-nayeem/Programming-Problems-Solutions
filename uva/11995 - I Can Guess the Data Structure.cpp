#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

int arr[MX];
int com[MX];

int check_queue(int n)
{
    queue<int> qu;
    for(int i = 0; i < n; i++)
    {
        if(com[i] == 1)
            qu.push(arr[i]);
        else if(qu.empty())
            return 0;
        else
        {
            if(qu.front() != arr[i])
                return 0;
            qu.pop();
        }
    }
    return 1;
}
int check_stack(int n)
{
    stack<int> qu;
    for(int i = 0; i < n; i++)
    {
        if(com[i] == 1)
            qu.push(arr[i]);
        else if(qu.empty())
            return 0;
        else
        {
            if(qu.top() != arr[i])
                return 0;
            qu.pop();
        }
    }
    return 1;
}
int check_pri_queue(int n)
{
    priority_queue<int> qu;
    for(int i = 0; i < n; i++)
    {
        if(com[i] == 1)
            qu.push(arr[i]);
        else if(qu.empty())
            return 0;
        else
        {
            if(qu.top() != arr[i])
                return 0;
            qu.pop();
        }
    }
    return 1;
}


int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d", &com[i], &arr[i]);

        int que = check_queue(n);
        int st = check_stack(n);
        int pqu = check_pri_queue(n);

        if(que+st+pqu == 0)
            printf("impossible\n");
        else if(que+st+pqu >= 2)
            printf("not sure\n");
        else if(que == 1)
            printf("queue\n");
        else if(st == 1)
            printf("stack\n");
        else
            printf("priority queue\n");
    }
    return 0;
}

