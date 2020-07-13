#include<cstdio>
#include<iostream>
#include<deque>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    deque<int> qu;
    int te, ti, n, t, k;
    char str[100];
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        printf("Case %d:\n", te);
        while(!qu.empty()) qu.pop_back();
        scanf("%d %d", &n, &t);
        for(int i = 0; i < t; i++)
        {
            scanf(" %s", str);
            if(str[1] == 'u')
            {
                scanf("%d", &k);
                if(qu.size() >= n)
                    printf("The queue is full\n");
                else
                {
                    if(str[4] == 'L')
                    {
                        qu.push_front(k);
                        printf("Pushed in left: %d\n", k);
                    }
                    else
                    {
                        qu.push_back(k);
                        printf("Pushed in right: %d\n", k);
                    }
                }
            }
            else if(str[1] == 'o')
            {
                if(qu.empty())
                    printf("The queue is empty\n");
                else
                {
                    if(str[3] == 'L')
                    {
                        printf("Popped from left: %d\n", qu.front());
                        qu.pop_front();
                    }
                    else
                    {
                        printf("Popped from right: %d\n", qu.back());
                        qu.pop_back();
                    }
                }
            }
        }
    }
    return 0;
}
