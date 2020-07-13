#include<cstdio>
#include<vector>
using namespace std;

#define lli long long int

lli fact[20];
vector<int> vc;

int main()
{
    fact[0] = 1;
    for(int i = 1; i < 20; i++)
        fact[i] = i * fact[i-1];
    lli n, m;
    int te, ti;

    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        vc.clear();
        m = n;
        for(int i = 19; i >= 0 && m > 0; i--)
        {
            if(m >= fact[i])
            {
                vc.push_back(i);
                m = m - fact[i];
                //printf("%d\n", i);
            }
        }
        if(m == 0)
        {
            printf("Case %d: %d!", te, vc[vc.size()-1]);
            for(int i = vc.size()-2; i >= 0; i--)
                printf("+%d!", vc[i]);
            puts("");
        }
        else
            printf("Case %d: impossible\n", te);
    }
}
