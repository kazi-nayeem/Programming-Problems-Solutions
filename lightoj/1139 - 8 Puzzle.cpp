#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

struct data
{
    char arr[3][3];
    data() {}
    data(int a)
    {
        for(int i = 2; i >= 0; i--)
            for(int j = 2; j >= 0; j--)
            {
                arr[i][j] = a%10;
                a /= 10;
            }
    }
    int value()
    {
        int total = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                total = total*10+arr[i][j];
        return total;
    }
};

map<int,int> mp;

void func(void)
{
    data tem, newt;

    for(int i = 0, k = 1; i < 3; i++)
        for(int j = 0; j < 3 && k < 10; j++)
            tem.arr[i][j] = k++;
    tem.arr[2][2] = 0;

    queue<int> qu;
    qu.push(tem.value());
    mp[tem.value()] = 0;

    while(!qu.empty())
    {
        int now = qu.front();
        qu.pop();
        int dis = mp[now];
        tem = data(now);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                if(tem.arr[i][j] == 0)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int tx = i+xx[k];
                        int ty = j+yy[k];
                        if(ty < 0 || tx < 0 || tx > 2 || ty > 2) continue;
                        newt = tem;
                        newt.arr[i][j] = newt.arr[tx][ty];
                        newt.arr[tx][ty] = 0;
                        int value = newt.value();
                        if(mp.find(value) == mp.end())
                        {
                            qu.push(value);
                            mp[value] = dis+1;
                        }
                    }
                    break;
                }
            }
    }
}

int main()
{
    func();
    int te, ti, value;
    data input;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
        {
            scanf(" %c", &input.arr[i][j]);
            input.arr[i][j] -= '0';
        }
        value = input.value();
        if(mp.find(value) == mp.end())
            printf("Case %d: impossible\n", te);
        else
            printf("Case %d: %d\n", te, mp[value]);
    }
    return 0;
}
