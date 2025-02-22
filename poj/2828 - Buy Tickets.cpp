#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

#define MX 250500
#define mlr int mid = (beg+fini)>>1;\
            int left = node << 1;\
            int right = left+1;

int arr[MX];
int res[MX];
int pos[MX];
int flag[MX];
int tree[MX*4];

void init(int node, int beg, int fini);
void update(int node, int beg, int fini, int pos);
int query(int node, int beg, int fini, int pos);

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) == 1) {

        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &pos[i], &arr[i]);
            pos[i]++;
            flag[i] = 1;
        }

        init(1,1,n);

        for(int i = n; i >= 1; i--) {
            res[query(1,1,n,pos[i])] = arr[i];
        }
        printf("%d", res[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", res[i]);
        puts("");
    }
    return 0;
}

void init(int node, int beg, int fini) {
    if(beg == fini) {
        tree[node] = flag[beg];
        return;
    }

    mlr;

    init(left,beg,mid);
    init(right,mid+1,fini);

    tree[node]=tree[left]+tree[right];
    return;
}

void update(int node, int beg, int fini, int pos) {
    if(beg == fini) {
        tree[node] = flag[beg];
        return;
    }

    mlr;

    if(pos <= mid) update(left,beg,mid, pos);
    else update(right,mid+1,fini, pos);

    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int beg, int fini, int pos) {
    if(beg == fini) {
        flag[beg] = 0;
        tree[node] = 0;
        return beg;
    }
    mlr;
    int p1 = 0, p2 = 0;
    if(tree[left] >= pos)
        p1 = query(left,beg,mid, pos);
    else
        p1 = query(right,mid+1,fini, pos-tree[left]);

    tree[node]=tree[left]+tree[right];
    return p1;
}

