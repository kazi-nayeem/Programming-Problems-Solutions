#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct maTix{
    int arr[2][2];
};

maTix mat, unit;
int mod;

maTix matexp(int p);
maTix multiply(maTix a, maTix b);

int main()
{
    unit.arr[0][0] = unit.arr[1][1] = 1;
    unit.arr[0][1] = unit.arr[1][0] = 0;
    mat.arr[0][0] = mat.arr[0][1] = mat.arr[1][0] = 1;
    mat.arr[1][1] = 0;

    int te, ti, a, b, n, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &a, &b, &n, &m);
        mod = 1;
        while(m--) mod *= 10;
        maTix res = matexp(n-1);
        printf("%d\n",(res.arr[0][0]*b+res.arr[0][1]*a)%mod);
    }
    return 0;
}

maTix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    if(p&1)
        return multiply(mat,matexp(p-1));
    maTix res = matexp(p/2);
    return multiply(res,res);
}
maTix multiply(maTix a, maTix b)
{
    maTix res;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            res.arr[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
        }
    return res;
}
