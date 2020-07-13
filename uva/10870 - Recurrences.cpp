#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define DI 15

typedef long long int ll;


struct matrix {
    ll arr[DI][DI];
    int row, col;
};

matrix mat, unit;
ll mod;
int arr[20];

matrix matexp(int p);
matrix multiply(matrix a, matrix  b);

int main()
{
    for(int i = 0; i < DI; i++)
        unit.arr[i][i] = 1;
    for(int i = 1; i < DI; i++)
        mat.arr[i][i-1] = 1;
    int n, m, d;
    while(scanf("%d%d%lld", &d, &n, &mod) == 3)
    {
        if(d == 0 && n == 0 && mod == 0) return 0;
        for(int i = 0; i < d; i++)
            scanf("%lld", &mat.arr[0][i]);
        for(int i = 0; i < d; i++)
            scanf("%d", &arr[i]);
        if(n <= d)
        {
            printf("%d\n", arr[n-1]);
            continue;
        }
        mat.row = d;
        mat.col = d;
        unit.row = d;
        unit.col = d;
        matrix res = matexp(n-d);
        ll ans = 0;
        for(int i = 0; i < d; i++)
        {
            ans += res.arr[0][i]*arr[d-i-1];
            ans %= mod;
        }
        printf("%lld\n", ans);
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
