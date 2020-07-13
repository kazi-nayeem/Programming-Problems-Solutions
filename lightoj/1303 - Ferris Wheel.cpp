#include<cstdio>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

struct data{
    int per, num;
    data(){}
    data(int a, int b)
    {
        per = a;
        num = b;
    }
};

int flag[21][21];

int func(int n, int k);

int main()
{
    int n, k, te = 1, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", te++, func(n,k));
    }
    return 0;
}

int func(int n, int k)
{
    memset(flag, 0, sizeof flag);

    int total = n*k, tim = 0;
    queue<data> que;
    deque<int> deq;
    stack<int> stk;

    for(int i = 1; i <= k; i++)
        que.push(data(0,i));
    for(int i = 1; i <= n; i++)
        deq.push_back(i);

    for(int i = 0; i < total;)
    {
        int j = que.front().num;
        if(que.front().per!=0)
            deq.push_back(que.front().per);
        que.pop(), tim++;
        int person = 0;
        while(!stk.empty()) stk.pop();
        while(!deq.empty())
        {
            if(flag[deq.front()][j] == 0)
            {
                person = deq.front();
                deq.pop_front();
                i++, flag[person][j] = 1;
                //printf("%d %d\n", person, j);
                break;
            }
            stk.push(deq.front());
            deq.pop_front();
        }
        while(!stk.empty()) deq.push_front(stk.top()), stk.pop();
        if(person == 0)
            que.push(data(0,j));
        else
            que.push(data(person,j));
    }
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
            printf("%d  ", flag[i][j]);
        puts("");
    }*/
    return (tim+k)*5;
}

