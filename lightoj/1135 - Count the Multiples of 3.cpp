#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100050
#define lrm int mid = (b+e)/2;\
            int left = node*2;\
            int right = left+1;

struct data
{
    int num[3];
    char add;
    data() {}
    data(int a, int b, int c,char d)
    {
        num[0]=a,num[1]=b,num[2]=c,add=d;
    }
    data operator + (const data &p) const
    {
        return data(num[0]+p.num[0],num[1]+p.num[1],num[2]+p.num[2],0);
    }
    void update(char a)
    {
        int tem;
        for(int i = 0; i < a; i++)
        {
            tem = num[2];
            num[2] = num[1];
            num[1] = num[0];
            num[0] = tem;
        }
        add = (add+a)%3;
        return;
    }
};

data tree[MX*3];

void init(int node, int b, int e);
int query(int node, int b, int e, int i, int j);
void update(int node, int b, int e, int i, int j, char val);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, q, n, x, y, t;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        init(1,0,n-1);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &t, &x, &y);
            if(t)
                printf("%d\n", query(1,0,n-1,x,y));
            else
                update(1,0,n-1,x,y,1);
        }
    }
    return 0;
}

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = data(1,0,0,0);
        return;
    }
    lrm;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
    return;
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(i <= b && e <= j) return tree[node].num[0];
    lrm;
    if(tree[node].add != 0)
    {
        update(left,b,mid,b,e,tree[node].add);
        update(right,mid+1,e,b,e,tree[node].add);
        tree[node] = tree[left]+tree[right];
    }
    return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
}
void update(int node, int b, int e, int i, int j, char val)
{
    if(i > e || j < b) return;
    if(i <= b && e <= j)
    {
        tree[node].update(val);
        return;
    }
    lrm;
    if(tree[node].add != 0)
    {
        update(left,b,mid,b,e,tree[node].add);
        update(right,mid+1,e,b,e,tree[node].add);
    }
    update(left,b,mid,i,j, val);
    update(right,mid+1,e,i,j, val);
    tree[node] = tree[left]+tree[right];
    return;
}
