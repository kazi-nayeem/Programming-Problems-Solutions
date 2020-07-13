#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define popc(a) (__builtin_popcount(a))

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int main()
{
    int n, ans = 0, pre = 0, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        if(pre == 0){
            scanf("%d", &pre);
            ans++;
        }else{
            pre--;
            scanf("%d", &x);
        }
    }
    printf("%d\n", ans);
    return 0;
}


