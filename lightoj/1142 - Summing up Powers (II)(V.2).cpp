#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct maTix
{
    int arr[60][60];
};

maTix mat, unit;
int mod = 10, rc;

maTix matexp(int p);
maTix multiply(maTix a, maTix b);

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
            mat.arr[i*2][i*2+1] = 1;
            mat.arr[i*2+1][i*2+1] = 1;
            for(int j = 0; j < n; j++)
                scanf(" %d", &mat.arr[i*2][j*2]);
        }
        rc = n*2;
        printf("Case %d:\n", te++);
        maTix res = matexp(m+1);
        for(int i = 0; i < rc; i+=2)
        {
            for(int j = 1; j < rc; j+=2)
            {
                if(i/2 != j/2)
                    printf("%d", res.arr[i][j]);
                else
                    printf("%d", (res.arr[i][j]+9)%10);
            }
            puts("");
        }
    }
    return 0;
}

maTix matexp(int p)
{
    if(p == 1) return mat;
    maTix res = mat;
    int st = 31;
    for(;st>0;st--)
        if((p>>st)&1)
            break;
    for(int i = st-1; i >= 0; i--)
    {
        res = multiply(res,res);
        if((p>>i)&1)
            res = multiply(res,mat);
    }
    return res;
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

