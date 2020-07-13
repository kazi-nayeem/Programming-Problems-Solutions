#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

map< pair<int,int>, int > mp;

int xx[1000];
int yy[1000];

int main()
{
    int te, ti;
    int n, res, x, y;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        res = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &xx[i], &yy[i]);
        for(int i = 0;i < n; i++)
        {
            mp.clear();
            for(int j = i+1; j < n; j++)
            {
                x = xx[i]-xx[j];
                y = yy[i]-yy[j];
                int g = __gcd(x,y);
                x /= g;
                y /= g;
                if(mp.find(make_pair(x,y)) == mp.end())
                {
                    mp[make_pair(x,y)] = 0;
                }
                res = max(res,++mp[make_pair(x,y)]);
            }
        }
        printf("Case %d: %d\n", te, res+1);
    }
    return 0;
}
