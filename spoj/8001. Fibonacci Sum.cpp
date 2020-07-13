#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define DI 3

typedef long long int ll;


struct matrix {
    ll arr[DI][DI];
};

matrix mat, unit, zero;
ll mod = 1000000007LL;

matrix matexp(int p);
matrix multiply(matrix a, matrix  b);

int main()
{
    unit.arr[0][0] = 1;
    unit.arr[1][1] = 1;
    unit.arr[2][2] = 1;
    mat.arr[0][0] = 1;
    mat.arr[0][1] = 1;
    mat.arr[0][2] = 1;
    mat.arr[1][1] = 1;
    mat.arr[1][2] = 1;
    mat.arr[2][1] = 1;
    int n, m, te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d%d", &n, &m);
        matrix res1 = matexp(n-2);
        matrix res2 = matexp(m-1);
        printf("%lld\n", (((res2.arr[0][0]-res1.arr[0][0]+res2.arr[0][1]-res1.arr[0][1])%mod)+mod)%mod);
    }
    return 0;
}

matrix matexp(int p)
{
    if(p < 0) return zero;
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
