#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned long long int llu;

int main()
{
    vector<llu> vc;
    int te, ti;
    llu n, k, last, m;
    scanf("%d", &ti);

    for(te = 1;te <= ti; te++)
    {
        scanf("%llu", &n);
        last = (sqrt(1+(8*n))-1);
        k = 0;
        m = n-1;
        for(llu i = 2, j; i <= last; i++)
        {
            //printf("%llu\n", k);
            if(n%i == 0) {
                if(i%2 == 1) vc.push_back(i),k++;
                j = n/i;
                if(j%2 == 1 && j != i) vc.push_back(j),k++;
            }
            if(m%i == 0)
            {
                if(i%2 == 0) vc.push_back(i),k++;
                j = m/i;
                if(j%2 == 0 && i != j) vc.push_back(j),k++;
            }
        }
        sort(vc.begin(),vc.end());
        for(int i = 0; i < vc.size(); i++)
            printf("%llu\n", vc[i]);
        printf("Case %d: %llu\n", te, k);
    }
    return 0;
}

