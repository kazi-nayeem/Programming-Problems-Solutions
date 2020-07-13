#include<cstdio>
#include<iostream>
using namespace std;

#define MX 100005
#define lli long long int
#define INF 4000000000000000000LL

lli arr[MX];
lli indx[MX];
lli ins[MX];
lli seq[MX];

void LIS(int n)
{
    for(int i = 1; i <= n; i++) ins[i] = INF;
    ins[0] = -1;
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        int beg = 0, en = n, mid;
        while(beg<=en)
        {
            mid = (en+beg)/2;
            if(ins[mid] < arr[i])
                beg = mid+1;
            else
                en = mid-1;
        }
        ins[beg] = arr[i];
        indx[i] = beg;
        if(beg>mx) mx = beg;
    }
    int te = mx;
    for(int i = n-1; i >= 0 && te > 0; i--)
    {
        if(indx[i] == te)
        {
            seq[te] = arr[i];
            te--;
        }
    }
    printf("Max hits: %d\n", mx);
    for(int i = 1; i <= mx; i++)
        printf("%lld\n", seq[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char str[15];
    int te, n;
    scanf(" %d", &te);
    gets(str);
    gets(str);
    while(te--)
    {
        n = 0;
        while(gets(str))
        {
            //printf("%s\n", str);
            if(str[0] == '\0') break;
            sscanf(str, " %lld", &arr[n++]);
        }
        LIS(n);
        if(te) puts("");
    }
    return 0;
}
