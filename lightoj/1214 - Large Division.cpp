#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char arr[205];

int main()
{
    int te, ti, len;
    long long int res, mod;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%s%lld", arr, &mod);
        len = strlen(arr);
        res = (arr[0] == '-')? 0:(arr[0]-'0')%mod;
        for(int i = 1; i < len; i++)
            res = (res*10+arr[i]-'0')%mod;
        if(res == 0)
            printf("Case %d: divisible\n", te);
        else
            printf("Case %d: not divisible\n", te);
    }
    return 0;
}
