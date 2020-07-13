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

struct data2
{
    int x, y, pos;
    ll sum;
    data2(int a, int b, int c, ll s)
    {
        x = a;
        y = b;
        pos = c;
        sum = s;
    }
    bool operator < (const data2 & p) const
    {
        //if(sum != p.num) return num < p.num;
        return sum > p.sum;
    }
};

ll tree[MX*4];
data arr[MX];
ll save[MX];
priority_queue<data2> qu;
vector<data2> now;

void update(int node, int beg, int en, int pos, int val)
{
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos)
    {
        tree[node] = val;
        return;
    }
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update(left,beg,mid,pos,val);
    update(right,mid+1,en,pos,val);
    tree[node] = (tree[left]+tree[right]);
}

ll query(int node, int beg, int en, int i, int j)
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

int main()
{
    int n, x, q;
    scanf("%d", &n);
    memset(tree,0,sizeof tree);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].num);
        arr[i].pos = i+1;
    }
    sort(arr,arr+n);

    while(qu.size()) qu.pop();
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        qu.push(data2(a,b,i,0ll));
    }
    for(int i = 0; i < n; i++)
    {
        while(qu.size())
        {
            data2 tem = qu.top();
            if(tem.sum+1 >= arr[i].num) break;
            qu.pop();
            tem.sum = query(1,1,n,tem.x,tem.y);
            //now.push_back(tem);
            if(tem.sum+1 >= arr[i].num)
            {
                qu.push(tem);
            }
            else
                save[tem.pos] = tem.sum+1;
        }
        update(1,1,n,arr[i].pos,arr[i].num);
    }
    while(qu.size())
    {
        data2 tem = qu.top();
        qu.pop();
        tem.sum = query(1,1,n,tem.x,tem.y);
        save[tem.pos] = tem.sum+1;
    }
    for(int i = 0; i < q; i++)
        printf("%lld\n", save[i]);
    return 0;
}
