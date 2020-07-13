#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

#define INF 2000000

void cle(void);
double floyd(int n);

map<int,int> mp;
int arr[100][100];

int main()
{
    int a, b, te = 1;
    while(scanf("%d %d", &a, &b) == 2)
    {
        if(a == 0 && b == 0) return 0;
        cle();
        mp[a] = 0;
        mp[b] = 1;
        arr[0][1] = 1;
        int mc = 2;
        while(scanf("%d %d", &a, &b) == 2)
        {
            if(a == 0 && b == 0) break;
            if(mp.find(a) == mp.end())
                mp[a] = mc++;
            if(mp.find(b) == mp.end())
                mp[b] = mc++;

            a = mp[a];
            b = mp[b];

            arr[a][b] = 1;

        }
        /*for(int i = 0; i < mc; i++)
        {
            for(int j = 0; j < mc; j++)
                printf("%d ", arr[i][j]);
            puts("");
        }*/
        printf("Case %d: average length between pages = %.3lf clicks\n", te++, floyd(mc));
    }
    return 0;
}

void cle(void)
{
    mp.clear();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
        arr[i][j] = (i == j)? 0 : INF;
    return;
}
double floyd(int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);

    double total = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        total += arr[i][j];

    return total / (n*(n-1));
}
