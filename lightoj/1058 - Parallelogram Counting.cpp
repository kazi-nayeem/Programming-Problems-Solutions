#include<cstdio>
#include<algorithm>
using namespace std;

#define MX 1000000

struct data{
    int a, b, x, y;
    bool operator < (const data & p) const
    {
        if(x != p.x) return x < p.x;
        if(y != p.y) return y < p.y;
        if(a != p.a) return a < p.a;
        return b < p.b;
    }
};

struct data2{int x, y;
    bool operator == (const data2 &p) const
    {
        if(x == p.x && y == p.y) return true;
        return false;
    }
};

data arr[MX];

int xx[1005];
int yy[1005];
data2 sava[1001][1001];

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        int pos = 0;
        for(int i = 0; i < n; i++)
            scanf("%d%d", &xx[i], &yy[i]);
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
        {
            sava[i][j].x = xx[i]-xx[j];
            sava[i][j].y = yy[i]-yy[j];
            int g = __gcd(sava[i][j].x, sava[i][j].y);
            sava[i][j].x /= g;
            sava[i][j].y /= g;
            sava[j][i] = sava[i][j];
            arr[pos].a = i;
            arr[pos].b = j;
            arr[pos].x = sava[i][j].x;
            arr[pos].y = sava[i][j].y;
            pos++;
        }
        sort(arr,arr+pos);
        /*printf("%d\n", pos);
        for(int i = 0; i < pos; i++)
            printf("%d %d %d %d\n", arr[i].a, arr[i].b, arr[i].x, arr[i].y);*/
        int res = 0;
        for(int i = 0; i < pos; i++)
        {
            for(int j = i+1; j < pos; j++)
            {
                if(arr[i].x != arr[j].x || arr[i].y != arr[j].y) break;
                if(arr[i].a == arr[j].a || arr[i].b == arr[j].a || arr[i].a == arr[j].b || arr[i].b == arr[j].b) continue;
                if(sava[arr[i].a][arr[j].a] == sava[arr[i].b][arr[j].b] || sava[arr[i].a][arr[j].b] == sava[arr[i].b][arr[j].a])
                    res++;
            }
        }
        printf("Case %d: %d\n", te, res/2);
    }
    return 0;
}
