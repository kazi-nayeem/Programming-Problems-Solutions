#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct maTix{
    int arr[4][4];
};

const int mod = 10007;
maTix mat, unit;


maTix matexp(int p);
maTix multiply(maTix a, maTix b);

int main()
{
    memset(unit.arr,0,sizeof unit.arr);
    for(int i = 0; i < 4; i++)
        unit.arr[i][i] = 1;
    int a, b, c, n, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        if(n <= 2)
        {
            printf("Case %d: 0\n", te);
            continue;
        }
        memset(mat.arr,0,sizeof mat.arr);
        mat.arr[0][0] = a;
        mat.arr[0][2] = b;
        mat.arr[0][3] = 1;
        mat.arr[1][0] = 1;
        mat.arr[2][1] = 1;
        mat.arr[3][3] = 1;
        maTix res = matexp(n-2);
        printf("Case %d: %d\n", te, (res.arr[0][3]*c)%mod);
    }
    return 0;
}

maTix matexp(int p)
{
    //if(p == 0) return unit;
    if(p == 1) return mat;
    int st;
    for(st = 28; st > 0; st--)
        if(((p>>st)&1) == 1)
        break;
    maTix res = mat;
    for(int i = st-1; i >= 0; i--)
    {
        res = multiply(res,res);
        if(((p>>i)&1) == 1)
            res = multiply(mat,res);
    }
    return res;
}

maTix multiply(maTix a, maTix b)
{
    maTix res;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
    {
        res.arr[i][j] = 0;
        for(int k = 0; k < 4; k++)
        {
            res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
            res.arr[i][j] %= mod;
        }
    }
    return res;
}
