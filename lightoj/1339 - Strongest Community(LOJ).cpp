#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100050

int tree[MX*4];
int arr[MX];

void build(int node, int beg, int en)
{
    if(beg == en)
    {
        tree[node] = arr[beg];
        //printf("node = %d tree = %d %d\n", node, tree[node], beg);
        return;
    }

    int mid = (beg+en)/2;
    int left = node*2;
    int right = left+1;

    build(left,beg,mid);
    build(right,mid+1,en);
    tree[node] = max(tree[left],tree[right]);
    //printf("node = %d tree = %d beg = %d en = %d\n", node, tree[node], beg, en);
    return;
}

int query(int node,int beg,int en,int i,int j)
{
    if(beg > j || en < i || i > j) return 0;
    //printf("%d %d %d %d tree = %d\n", beg, en, i, j, tree[node]);
    if(beg >= i && en <= j)
        return tree[node];

    int mid = (beg+en)/2;
    int left = node*2;
    int right = left+1;

    int q1 = query(left,beg,mid,i,j);
    int q2 = query(right,mid+1,en,i,j);
    //printf("node = %d tree = %d beg = %d en = %d max = %d\n", node, tree[node], beg, en, max(q1,q2));
    return max(q1,q2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, c, q, te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &n, &c, &q);
        int tm1, tm2 = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &tm1);
            if(tm1 == tm2)
                arr[i] = arr[i-1]+1;
            else
                arr[i] = 1;
            tm2 = tm1;
        }
        //for(int i = 1; i <= n; i++)
            //printf("%d ", arr[i]);
        //puts("");
        build(1,1,n);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &tm1, &tm2);
            //printf("%d %d", tm1, tm2);
            int k = tm1;
            for(; arr[k] != 1 && k < tm2; k++);
            int res;
            //printf(" %d\n", k);
            int res1;
            if(k == tm2)
            {
                if(arr[tm2] == 1 && tm1 != tm2)
                    res1 = tm2 - tm1;
                else
                    res1 = tm2-tm1+1;
                res = 0;
            }
            else
            {
                res1 = query(1,1,n,k,tm2);
                res = k - tm1;
            }
            printf("%d\n", max(res1, res));
        }
    }
    return 0;
}
