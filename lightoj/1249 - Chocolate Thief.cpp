#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct data{int vol;
    char name[25];
    bool operator < (const data& p) const
    {
        return vol < p.vol;
    }
};

data arr[105];

int main()
{
    int te, ti, a, b, c, n;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d%d%d", arr[i].name, &a, &b, &c);
            arr[i].vol = a * b * c;
        }
        sort(arr,arr+n);
        if(arr[0].vol == arr[n-1].vol)
            printf("Case %d: no thief\n", te);
        else
            printf("Case %d: %s took chocolate from %s\n", te, arr[n-1].name, arr[0].name);
    }
    return 0;
}
