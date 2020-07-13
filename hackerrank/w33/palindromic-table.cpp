//#include <bits/stdc++.h>

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
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> arr[MX];
vector<int> mask[MX];
vector<int> cnt[MX];

int mp[1050];
int rx1, rx2, ry1, ry2;

void calc(int row, int col)
{
    for(int i = 0; i <= row; i++)
        for(int j = 0, digi = 0; j <= col; j++)
        {
            if(arr[i][j] == 0) digi++;
            cnt[i].push_back(digi);
        }
    for(int i = 1; i <= row; i++)
        for(int j = 0; j <= col; j++)
        {
            cnt[i][j] += cnt[i-1][j];
        }
}

int zeroCount(int x1, int x2, int y1, int y2)
{
    return cnt[x2][y2]+cnt[x1-1][y1-1]-cnt[x1-1][y2]-cnt[x2][y1-1];
}

void compare(int & res, int x1, int x2, int y1, int y2)
{
    int area = (x2-x1+1)*(y2-y1+1);
    if(area>res && (area <= 1 || ((area-zeroCount(x1,x2,y1,y2))>1)))
    {
        res = area;
        rx1 = x1;
        rx2 = x2;
        ry1 = y1;
        ry2 = y2;
    }
}

int func(int row, int col)
{
    calc(row,col);
    for(int i = 0; i <= col; i++)
    {
        int now = 0;
        for(int j = 0; j <= row; j++)
        {
            now ^= 1<<arr[j][i];
            mask[j].push_back(now);
            //printf("(%d,%d) ", mask[i][j], arr[i][j]);
        }
        //puts("");
    }
//    for(int i = 0; i <= row; i++, puts(""))
//        for(int j = 0; j <= col; j++)
//            printf("(%d) ", mask[i][j]);
    int res = 0;
    for(int i = 1; i <= row; i++)
        for(int j = i; j <= row; j++)
        {
            //printf("%d %d--->>>\n", i, j);
            memset(mp,-1,sizeof mp);
            int now = 0;
            mp[now] = 0;
            for(int k = 1; k <= col; k++)
            {
                now ^= mask[i-1][k]^mask[j][k];
                //printf("%d ", now);
                if((j-i+1)%2 == 1)
                {
                    for(int l = 0; l < 10; l++)
                    {
                        int total = now^(1<<l);
                        if(mp[total] == -1) continue;
                        compare(res,i,j,mp[total]+1,k);
                    }
                }
                if(mp[now] != -1)
                {
                    compare(res,i,j,mp[now]+1,k);
                }
                else
                {
                    mp[now] = k;
                }
            }
            //puts("");
        }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int row, col;
    scanf("%d %d", &row, &col);
    bool flag = false;
    if(row<=col)
    {
        for(int i = 0; i <= col; i++)
            arr[0].push_back(0);
        for(int i = 1; i <= row; i++)
        {
            arr[i].push_back(0);
            for(int j = 1; j <= col; j++)
            {
                int x;
                scanf("%d", &x);
                arr[i].push_back(x);
            }
        }
    }
    else
    {
        for(int i = 0; i <= row; i++)
            arr[0].push_back(0);
        for(int i = 1; i <= col; i++)
            arr[i].push_back(0);
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                int x;
                scanf("%d", &x);
                arr[j].push_back(x);
            }
        }
        swap(row,col);
        flag = true;
    }
    //puts("ok");
    int res = func(row,col);
    printf("%d\n", res);
    rx1--;
    rx2--;
    ry1--;
    ry2--;
    if(flag)
    {
        swap(rx1,ry1);
        swap(rx2,ry2);
    }
    printf("%d %d %d %d\n", rx1, ry1, rx2, ry2);
    return 0;
}


