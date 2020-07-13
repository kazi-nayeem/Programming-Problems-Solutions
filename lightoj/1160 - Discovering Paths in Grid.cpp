#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

#define DI 35
#define ll long long

struct maTrix{
    ll int arr[DI][DI];
};

map<int,int> mp;

int save[100];
ll int mod = 1000000007;
maTrix mat;

bool check(int a, int b)
{
    for(int i = 1; i <= 7; i++)
    {
        if(((a>>i)&1) == 1)
        {
            if(((b>>(i-1))&1) == 1)
            {
                b ^= 1<<(i-1);
                continue;
            }
            if(((b>>(i+1))&1) == 1)
            {
                b ^= 1<<(i+1);
                continue;
            }
            return false;
        }
    }
    return true;
}

maTrix multiply(maTrix a, maTrix b)
{
    maTrix res;
    for(int i = 0; i < DI; i++)
        for(int j = 0; j < DI; j++)
        {
            res.arr[i][j] = 0;
            for(int k = 0; k < DI; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
        }
    return res;
}

maTrix matexp(int p)
{
    if(p == 1) return mat;
    maTrix res = mat;
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

int main()
{
    int pos = 0, res;
    for(int i = 1; i <= 7; i++)
        for(int j = i+1; j <= 7; j++)
            for(int k = j+1; k <= 7; k++)
                for(int l = k+1; l <= 7; l++)
                {
                    res = (1<<i)|(1<<j)|(1<<k)|(1<<l);
                    mp[res] = pos;
                    save[pos] = res;
                    pos++;
                }
    //printf("%d\n", mp.size());
    for(int i = 0; i < pos; i++)
        for(int j = 0; j < pos; j++)
        {
            if(check(save[i], save[j]))
                mat.arr[i][j] = 1;
            else
                mat.arr[i][j] = 0;
        }

    int te, ti , n, a;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        pos = 0;
        for(int i = 1; i <= 7; i++)
        {
            scanf("%d", &a);
            if(a == 0) continue;
            pos |= 1<<i;
        }
        if(n == 1)
        {
            printf("Case %d: 1\n", te);
            continue;
        }
        pos = mp[pos];
        maTrix tem = matexp(n-1);
        ll int fina = 0;
        for(int i = 0; i < DI; i++)
        {
            fina += tem.arr[pos][i];
            fina %= mod;
        }
        printf("Case %d: %lld\n", te, fina);
    }
    return 0;
}
