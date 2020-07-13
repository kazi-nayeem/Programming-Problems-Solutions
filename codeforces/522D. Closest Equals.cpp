#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

#define inf 10000000
#define MX 500005

struct point
{
    int x, y, pos;
    bool operator < (const point& p) const
    {
        return y<p.y;
    }
};


point que[MX];
int res[MX];
int pre[MX];
int pos[MX];
int tree[4*MX];
map<int,int> mp;


void init(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = inf;
        return;
    }
    int i = node<<1;
    int j = i+1;
    int mid = (l+r)/2;
    init(i,l,mid);
    init(j,mid+1,r);
    tree[node] = inf;
}

void update(int node, int l, int r, int pos, int val)
{
    if(l > pos || r < pos) return;
    if(l == pos && pos == r)
    {
        tree[node] = val;
        return;
    }
    int i = node<<1;
    int j = i+1;
    int mid = (l+r)/2;
    update(i,l,mid,pos,val);
    update(j,mid+1,r,pos,val);
    tree[node] = min(tree[i],tree[j]);
}

int query(int node, int l, int r, int a, int b)
{
    if(l > b || r < a) return inf;
    if(a <= l && b >= r)
    {
        return tree[node];
    }
    int i = node<<1;
    int j = i+1;
    int mid = (l+r)/2;
    return min(query(i,l,mid,a,b),query(j,mid+1,r,a,b));
}

int main()
{
    int n, q, x;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if(mp.find(x) == mp.end()) mp[x] = i;
        x = mp[x];
        pre[i] = pos[x];
        pos[x] = i;
    }
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d", &que[i].x, &que[i].y);
        que[i].pos = i;
    }
    sort(que,que+q);
    init(1,1,n);
    int save = 0;
    for(int i = 0; i < q; i++)
    {
        while(save<que[i].y)
        {
            save++;
            update(1,1,n,pre[save],save-pre[save]);
        }
        res[que[i].pos] = query(1,1,n,que[i].x,que[i].y);
        if(res[que[i].pos] == inf) res[que[i].pos] = -1;
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}
