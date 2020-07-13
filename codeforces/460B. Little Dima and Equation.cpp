#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

typedef long long int lli;

vector<lli> vc;

lli digit_sum(lli n)
{
    lli total = 0;
    for(; n>0; n/=10)
        total += n%10;
    return total;
}

int main()
{
    lli x, a, b, c;
    while(scanf("%I64d %I64d %I64d", &a, &b, &c) == 3)
    {
        vc.clear();
        for(lli i = 1ll; i <= 81ll; i++)
        {
            lli k = i;
            for(lli j = 1ll; j < a; j++)
                k *= i;
            x = (lli)b*k+c;
            if( x <= 0 || x >= 1000000000ll) continue;
            if(digit_sum(x) == i)
                vc.push_back(x);
        }
        printf("%d", (int) vc.size());
        if(vc.size())
            printf("\n%I64d", vc[0]);
        for(int i = 1; i < vc.size(); i++)
            printf(" %I64d", vc[i]);
        putchar('\n');
    }
    return 0;
}
