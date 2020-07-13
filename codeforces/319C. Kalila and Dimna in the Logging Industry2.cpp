#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define LL long long
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint PF("Case #%d: ",++cas);

#define lim 1000050

ll M[lim], C[lim];

bool bad(int l1, int l2, int l3)
{
    return (1.0*(C[l3]-C[l1])/(M[l1]-M[l3]))<(1.0*(C[l2]-C[l1])/(M[l1]-M[l2]));
}

void add(ll m, ll c, int &last)
{
    M[last] = m;
    C[last++] = c;
    while(last>=3&&bad(last-3,last-2,last-1))
    {
        M[last-2] = M[last-1];
        C[last-2] = C[last-1];
        last--;
    }
    return;
}

ll query(ll x, int &pointer, int last)
{
    if(pointer>=last)
        pointer = last-1;
    while(pointer<last-1 && M[pointer+1]*x+C[pointer+1] < M[pointer]*x+C[pointer])
        pointer++;
    return M[pointer]*x+C[pointer];
}

#define MX 1000005

ll a[MX];
ll b[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &b[i]);
    }
    int last = 0, pointer = 0;
    ll cost = 0;
    add(b[1],0,last);
    for(int i = 2; i <= n; i++)
    {
        cost = query(a[i],pointer,last);
        add(b[i],cost,last);
    }
    printf("%I64d\n", cost);
    return 0;
}
















