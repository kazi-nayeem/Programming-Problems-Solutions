#include<cstdio>
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MX 36

int x[50];
int y[50];

struct maTix
{
    unsigned int arr[MX][MX];
};

maTix mat, unit;

bool check(int a1, int b1, int a2, int b2);
maTix matexp(int p);
maTix multiply(maTix a, maTix b);

int main()
{
    unsigned int pos = 0, res = 0;
    for(int i = 1; i < 11; i++)
        for(int j = i+2; j < 11; j++, pos++)
            x[pos] = i, y[pos] = j;
    for(int i = 0; i < pos; i++)
    {
        unit.arr[i][i] = 1;
        for(int j = 0; j < pos; j++)
            if(check(x[i],y[i],x[j],y[j])) mat.arr[i][j] = 1, res++;
    }
    unsigned int te, ti, n;
    scanf("%u", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%u", &n);
        maTix result = matexp(n-1);
        res = 0;
        for(int i = 0; i < 36; i++)
            for(int j = 0; j < 36; j++)
                res += result.arr[i][j];
        printf("Case %u: %u\n", te, res);
    }
    return 0;
}

maTix matexp(int p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    if(p&1)
        return multiply(mat,matexp(p-1));
    maTix tem = matexp(p/2);
    return multiply(tem,tem);
}

maTix multiply(maTix a, maTix b)
{
    maTix res;
    memset(res.arr, 0, sizeof res.arr);
    for(int i = 0; i < 36; i++)
        for(int j = 0; j < 36; j++)
            for(int k = 0; k < 36; k++)
            res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
    return res;
}

bool check(int a1, int b1, int a2, int b2)
{
    if((abs(a1-a2)<2) || (abs(a1-b2)<2) || (abs(b1-a2)<2) || (abs(b1-b2)<2)) return false;
    return true;
}
