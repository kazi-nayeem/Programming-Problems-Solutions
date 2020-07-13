#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 100005
#define MXP 4794
#define ll long long

struct data
{
    int pos, num;
    bool operator < (const data & p) const
    {
        if(num != p.num) return num < p.num;
        return pos > p.pos;
    }
};

int tree[MX*4];
data arr[MX];
int save[MX];

const int mod = 1000000007;

void update(int node, int beg, int en, int pos, int val)
{
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos)
    {
        tree[node] += val;
        tree[node] %= mod;
        return;
    }
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update(left,beg,mid,pos,val);
    update(right,mid+1,en,pos,val);
    tree[node] = (tree[left]+tree[right])%mod;
}

int query(int node, int beg, int en, int i, int j)
{
    if(beg > j || i > en) return 0;
    if(i <= beg && en <= j)
        return tree[node];
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    ll ans = query(left,beg,mid,i,j);
    ans += query(right,mid+1,en,i,j);
    return ans%mod;
}

int main()
{
    int te, ti, n, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        memset(tree,0,sizeof tree);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i].num);
            arr[i].pos = i+1;
        }
        sort(arr,arr+n);
        int dif = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || arr[i].num != arr[i-1].num) dif++;
            save[arr[i].pos] = dif;
        }
        update(1,0,dif,0,1);
        for(int i = 1; i <= n; i++)
        {
            int add = query(1,0,dif,0,save[i]-1);
            update(1,0,dif,save[i],add);
        }
        printf("Case %d: %d\n", te, query(1,0,dif,1,dif));
    }
    return 0;
}
