#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define DI 16

typedef long long int ll;


struct matrix
{
    ll arr[DI][DI];
    int row, col;
};

matrix mat, unit;
ll mod = 1000000000LL;
int arr[20];

matrix matexp(int p);
matrix multiply(matrix a, matrix  b);
ll calc(int n);
ll func(ll n, int d);

int main()
{
    for(int i = 0; i < DI; i++)
        unit.arr[i][i] = 1;
    for(int i = 2; i < DI; i++)
        mat.arr[i][i-1] = 1;
    ll n, m;
    int d, te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &d);
        mat.row = d+1;
        mat.col = d+1;
        unit.row = d+1;
        unit.col = d+1;
        for(int i = 0; i < d; i++)
            scanf("%d", &arr[i]);
        arr[d] = calc(d);
        mat.arr[0][0] = 1;
        for(int i = 0; i < d; i++)
        {
            scanf("%lld", &mat.arr[0][i]);
            mat.arr[1][i] = mat.arr[0][i];
        }
        scanf("%lld%lld%lld",&n, &m, &mod);
        ll ans1 = func(n-1,d);
        ll ans2 = func(m,d);
        printf("%lld\n", ans2-ans2);
    }
    return 0;
}

matrix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    if(p&1)
        return multiply(mat,matexp(p-1));
    matrix res = matexp(p/2);
    return multiply(res,res);
}

matrix multiply(matrix  a, matrix  b)
{
    matrix res;
    mem(res.arr,0);
    res.row = a.row;
    res.col = b.col;
    for(int i = 0; i < a.row; i++)
        for(int j = 0; j < b.col; j++)
            for(int k = 0; k < a.col; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
    return res;
}

ll calc(int n)
{
    ll total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i];
    return total%mod;
}

ll func(ll n, int d)
{
    if(n <= d) return calc(n);
    matrix res = matexp(n-d);
    ll ans = 0;
    for(int i = 0; i <= d; i++)
    {
        ans += res.arr[0][i]*arr[d-i];
        ans %= mod;
    }
    return ans;
}
