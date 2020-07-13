#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define DI 4

const int mod = 10007;

struct matrix
{
    int arr[DI][DI];
};

matrix mat, unit;

matrix matexp(int p);
matrix multiply(matrix & a, matrix & b);

int main()
{
    for(int i = 0; i < DI; i++)
        unit.arr[i][i] = 1, mat.arr[0][i] = 1;
    mat.arr[1][0] = 1;
    mat.arr[2][1] = 1;
    mat.arr[2][3] = 1;
    mat.arr[3][1] = 1;
    mat.arr[3][2] = 1;

    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        matrix res = matexp(n);
        int ans = res.arr[0][0];
        printf("Case %d: %d\n", te, ans);
    }
    return 0;
}

matrix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    matrix res = mat;
    int st;
    for(st = 31; st >= 0; st--)
        if(((p>>st)&1) == 1)
            break;
    for(st--; st >= 0; st--)
    {
        res = multiply(res,res);
        if(((p>>st)&1) == 1)
            res = multiply(res,mat);
    }
    return res;
}
matrix multiply(matrix & a, matrix & b)
{
    matrix res;
    memset(res.arr, 0, sizeof res.arr);
    for(int i = 0; i < DI; i++)
        for(int j = 0; j < DI; j++)
            for(int k = 0; k < DI; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
    return res;
}
