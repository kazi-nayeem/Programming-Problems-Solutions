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

int tree[MX*4];
int arr[MX];
int save[MX];

const int mod = 1000000007;

void update(int node, int beg, int en, int pos, int val)
{
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos)
    {
        tree[node] += val;
        return;
    }
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update(left,beg,mid,pos,val);
    update(right,mid+1,en,pos,val);
    tree[node] = (tree[left]+tree[right]);
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
    return ans;
}

vector<pair<int,int> > mp;

int main()
{
    int te, ti, n, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        mp.clear();
        memset(tree,0,sizeof tree);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            mp.push_back(make_pair(arr[i],i));
        }
        sort(mp.begin(), mp.end());
        ll res = 0;
        for(int i = n-1; i >= 0;i--)
        {
            //printf("%lld\n", res);
            //printf("%d %d\n", mp[i].first, mp[i].second);
            int pos = mp[i].second;
            res += query(1,1,n,1, pos);
            update(1,1,n,pos,1);
        }
        printf("%lld\n", res);

    }
    return 0;
}
