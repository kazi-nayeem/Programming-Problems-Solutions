#include<cstdio>
#include<vector>
using namespace std;

#define LLI long long int
#define pb push_back

int main()
{
    vector <LLI> result;
    LLI n, m, o;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        if(n < 2 || m < 2)
        {
            printf("Boring!\n");
            continue;
        }
        result.clear();
        o = n;
        while(n%m == 0)
        {
            n /= m;
            result.pb(n);
        }
        if(n == 1)
        {
            int siz;
            siz = result.size();
            printf("%lld", o);
            for(int i = 0; i < siz; i++)
                printf(" %lld", result[i]);
            printf("\n");
        }
        else
            printf("Boring!\n");
    }
    return 0;
}

