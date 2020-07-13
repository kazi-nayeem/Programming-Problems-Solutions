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
#include <unordered_map>
using namespace std;

#define MX 100005
#define MXP 4794
#define ll long long

int tree[MX*4];

void update(int node, int beg, int en, int pos, int val) {
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos) {
        tree[node] = val;
        return;
    }

    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update(left,beg,mid,pos,val);
    update(right,mid+1,en,pos,val);
    tree[node] = __gcd(tree[left],tree[right]);
    return;
}

int cnt[MX];
unordered_map<int,int> mp;

int main() {
    int n, x, ase = 0;
    char ch;
    scanf("%d", &n);
    int pos = 0;
    for(int i = 0; i < n; i++) {
        scanf(" %c %d", &ch, &x);
        if(ch == '+') {
            ase++;
            if(mp.find(x) == mp.end()) {
                mp[x] = pos++;
            }
            int now = mp[x];
            cnt[now]++;
            if(cnt[now] == 1) {
                update(1,0,n-1,now,x);
            }
        } else {
            ase--;
            int now = mp[x];
            cnt[now]--;
            if(cnt[now] == 0) {
                update(1,0,n-1,now,0);
            }
        }
        if(ase > 0)
            printf("%d\n", tree[1]);
        else
            puts("1");
    }
    return 0;
}
