#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct maTix
{
    int arr[30][30];
};

maTix mat, unit;
int mod = 10, rc;

maTix matexp(int p);
maTix multiply(maTix a, maTix b);
maTix mat_sum(maTix a, maTix b);
maTix func(int p);

int main()
{
    int n, m, te = 1, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d%d", &n, &m);
        memset(mat.arr,0,sizeof mat.arr);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                scanf(" %d", &mat.arr[i][j]);
        }
        rc = n;
        printf("Case %d:\n", te++);
        maTix res = func(m);
        for(int i = 0; i < rc; i++)
        {
            for(int j = 0; j < rc; j++)
                printf("%d", res.arr[i][j]);
            puts("");
        }
    }
    return 0;
}

maTix func(int p)
{
    if(p == 1) return mat;
    maTix res = func(p/2);
    maTix pow = matexp(p/2);
    res = mat_sum(res,multiply(pow,res));
    if(p&1)
    {
        pow = multiply(pow,pow);
        pow = multiply(pow,mat);
        return mat_sum(res,pow);
    }
    return res;
}

maTix matexp(int p)
{
    if(p == 1) return mat;
    if(p&1)
        return multiply(mat,matexp(p-1));
    maTix res = matexp(p/2);
    return multiply(res,res);
}
maTix multiply(maTix a, maTix b)
{
    maTix res;
    for(int i = 0; i < rc; i++)
        for(int j = 0; j < rc; j++)
        {
            res.arr[i][j] = 0;
            for(int k = 0; k < rc; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
        }
    return res;
}

maTix mat_sum(maTix a, maTix b)
{
    maTix res;
    for(int i = 0; i < rc; i++)
        for(int j = 0; j < rc; j++)
        {
            res.arr[i][j] = a.arr[i][j]+b.arr[i][j];
            res.arr[i][j] %= mod;
        }
    return res;
}
