#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define DI 2

typedef long long int ll;


struct matrix {
    ll arr[DI][DI];
};

matrix mat, unit;
ll mod;

matrix matexp(int p);
matrix multiply(matrix a, matrix  b);

int main()
{
    unit.arr[0][0] = 1;
    unit.arr[1][1] = 1;
    mat.arr[0][0] = 1;
    mat.arr[0][1] = 1;
    mat.arr[1][0] = 1;
    int n, m;
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d%d", &n, &m);
        mod = 1<<m;
        matrix res = matexp(n);
        printf("%lld\n", res.arr[0][0]);
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
    for(int i = 0; i < DI; i++)
        for(int j = 0; j < DI; j++)
            for(int k = 0; k < DI; k++)
    {
            res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
            res.arr[i][j] %= mod;
    }
    return res;
}
