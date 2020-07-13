#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;

struct point{
    int x, y, pos;
    bool operator < (const point& p) const
    {
        return y<p.y;
    }
};


point que[50005];
int res[50005];
int pre[100005];
int pos[100005];
int tree[400005];

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
    tree[node] = tree[i]+tree[j];
}

int query(int node, int l, int r, int a, int b)
{
    if(l > b || r < a) return 0;
    if(a <= l && b >= r)
    {
        return tree[node];
    }
    int i = node<<1;
    int j = i+1;
    int mid = (l+r)/2;
    return query(i,l,mid,a,b)+query(j,mid+1,r,a,b);
}

int main()
{
    int te, ti, n, q, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        memset(tree,0,sizeof tree);
        memset(pos,-1,sizeof pos);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            pre[i] = pos[x];
            pos[x] = i;
        }
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &que[i].x, &que[i].y);
            que[i].pos = i;
        }
        sort(que,que+q);
        int save = 0;
        for(int i = 0; i < q; i++)
        {
            while(save<que[i].y)
            {
                save++;
                update(1,1,n,pre[save],0);
                update(1,1,n,save,1);
            }
            res[que[i].pos] = query(1,1,n,que[i].x,que[i].y);
        }
        printf("Case %d:\n", te);
        for(int i = 0;i < q; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}
