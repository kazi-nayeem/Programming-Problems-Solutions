#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 200005
#define ll long long
#define inf 234000000000000ll

int arr[MX];
ll tree[MX*5];
int pos[MX*5];

void init(int node,int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        pos[node] = b;
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[left] < tree[right])
    {
        tree[node] = tree[left];
        pos[node] = pos[left];
    }
    else
    {
        tree[node] = tree[right];
        pos[node] = pos[right];
    }
    return;
}

pair<ll,int> query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return make_pair(inf,inf);
    if(b >= i && e <= j) return make_pair(tree[node],pos[node]);
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    pair<ll,int> lf = query(left,b,mid,i,j);
    pair<ll,int> ri = query(right,mid+1,e,i,j);
    if(lf.first < ri.first) return lf;
    return ri;
}

ll mx[MX];
int n;

void func(int i, int j)
{
    if(i > j) return;
    pair<ll,int> pi = query(1,0,n-1,i,j);
    mx[j-i+1] = max(mx[j-i+1],pi.first);
    func(pi.second+1,j);
    func(i,pi.second-1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    init(1,0,n-1);
    func(0,n-1);
    for(int i = n-1; i >= 0; i--)
        mx[i] = max(mx[i],mx[i+1]);
    for(int i = 1; i <= n; i++)
        printf("%I64d ", mx[i]);
    puts("");
    return 0;
}
