#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

#define MX 100005

int flag[MX];

int main()
{
    int time, total;
    int card, connect;
    int x, y;
    scanf("%d", &time);

    while(time--)
    {
        scanf("%d %d", &card, &connect);
        total = 0;
        for(int i = 0; i < connect; i++)
        {
            scanf("%d %d", &x, &y);
            flag[y] = 1;
        }

        for(int i = 1; i <= card; i++)
        {
            if(flag[i] == 0) total++;
            flag[i] = 0;
        }
        printf("%d\n", total);
    }
    return 0;
}
