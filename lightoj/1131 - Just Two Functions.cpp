#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct maTix
{
    int arr[6][6];
};

int mod;
maTix mat, unit;


maTix matexp(int p);
maTix multiply(maTix a, maTix b);

int main()
{
    //freopen("input.txt", "r", stdin);
    memset(unit.arr,0,sizeof unit.arr);
    for(int i = 0; i < 6; i++)
        unit.arr[i][i] = 1;
    int a1, b1, c1, a2, b2, c2;
    int f0, f1, f2, g0, g1, g2;
    int q, n, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &a1, &b1, &c1);
        scanf("%d%d%d", &a2, &b2, &c2);
        scanf("%d%d%d", &f0, &f1, &f2);
        scanf("%d%d%d", &g0, &g1, &g2);
        scanf("%d", &mod);
        memset(mat.arr,0,sizeof mat.arr);
        mat.arr[0][0] = a1;
        mat.arr[0][1] = b1;
        mat.arr[0][5] = c1;
        mat.arr[3][3] = a2;
        mat.arr[3][4] = b2;
        mat.arr[3][2] = c2;
        mat.arr[1][0] = 1;
        mat.arr[2][1] = 1;
        mat.arr[4][3] = 1;
        mat.arr[5][4] = 1;
        scanf("%d", &q);
        printf("Case %d:\n", te);
        while(q--)
        {
            scanf("%d", &n);
            if(n < 3)
            {
                if(n == 0)
                    printf("%d %d\n", f0%mod, g0%mod);
                else if(n == 1)
                    printf("%d %d\n", f1%mod, g1%mod);
                else
                    printf("%d %d\n", f2%mod, g2%mod);
                continue;
            }
            maTix res = matexp(n-2);
            int re1, re2;
            re1 = res.arr[0][0]*f2+res.arr[0][1]*f1+res.arr[0][2]*f0+res.arr[0][3]*g2+res.arr[0][4]*g1+res.arr[0][5]*g0;
            re2 = res.arr[3][0]*f2+res.arr[3][1]*f1+res.arr[3][2]*f0+res.arr[3][3]*g2+res.arr[3][4]*g1+res.arr[3][5]*g0;
            //re2 = res.arr[3][3]*g2+res.arr[3][4]*g1+res.arr[3][2]*f0;
            printf("%d %d\n", re1%mod, re2%mod);
        }
    }
    return 0;
}

maTix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    int st;
    for(st = 31; st > 0; st--)
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
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            res.arr[i][j] = 0;
            for(int k = 0; k < 6; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
        }
    return res;
}
