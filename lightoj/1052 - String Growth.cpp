#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
using namespace std;

#define DI 2
#define ll long long int
#define pii pair< ll , ll >

struct maTrix{
    ll arr[DI][DI];
};

maTrix mat, unit;
const ll mod = 1000000007LL;

maTrix matexp(int p);
maTrix multiply(maTrix a, maTrix b);
pii solution(maTrix fir,int l1, maTrix sec,int l2);

int main()
{
    unit.arr[0][0] = 1;
    unit.arr[1][1] = 1;
    mat.arr[0][1] = 1;
    mat.arr[1][0] = 1;
    mat.arr[1][1] = 1;
    int te, ti, n, m, k, x, y;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d %d %d", &n, &x, &m, &y, &k);
        maTrix res1 = matexp(n-1);
        maTrix res2 = matexp(m-1);
        pii sol = solution(res1,x,res2,y);
        //printf("%lld %lld\n", sol.first, sol.second);
        if(sol.first == -1)
        {
            printf("Case %d: Impossible\n", te);
            continue;
        }
        maTrix res = matexp(k-1);
        ll x1 = res.arr[0][0]+res.arr[1][0];
        ll y1 = res.arr[0][1]+res.arr[1][1];
        x1 %= mod;
        y1 %= mod;
        printf("Case %d: %lld\n", te, ((x1*sol.first)+(y1*sol.second))%mod);
    }
    return 0;
}

maTrix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    maTrix res = mat;
    int st;
    for(st = 31; st >= 0; st--)
        if(((p>>st)&1) == 1)
            break;
    for(st--;st>=0;st--)
    {
        res = multiply(res,res);
        if(((p>>st)&1) == 1)
            res = multiply(res,mat);
    }
    return res;
}
maTrix multiply(maTrix a, maTrix b)
{
    maTrix res;
    memset(res.arr,0,sizeof res.arr);
    for(int i = 0; i < DI; i++)
        for(int j = 0; j < DI; j++)
            for(int k = 0; k < DI; k++)
    {
        res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
        res.arr[i][j] %= mod;
    }
    return res;
}

pii solution(maTrix fir,int l1, maTrix sec,int l2)
{
    ll x1, x2, y1, y2;
    x1 = fir.arr[0][0]+fir.arr[1][0];
    y1 = fir.arr[0][1]+fir.arr[1][1];
    x2 = sec.arr[0][0]+sec.arr[1][0];
    y2 = sec.arr[0][1]+sec.arr[1][1];
    ll b =  (ll) ((l2*x1)-(x2*l1))/((x1*y2)-(x2*y1));
    ll a = (l1 - (y1*b))/x1;
    if(b < 0 || a < 0 || ((x1*a+y1*b) != l1) || ((x2*a+y2*b) != l2))
        return make_pair(-1,-1);
    return make_pair(a,b);
}
