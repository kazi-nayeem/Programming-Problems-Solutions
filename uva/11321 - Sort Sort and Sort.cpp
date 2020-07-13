#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define MX 10005

struct data{
            int n, mo, en;
        data(){}
        data(int a, int b)
        {
            n = a;
            mo = a % b;
            en = a & 1;
        }
        bool operator < (const data& p) const
        {
            if(mo != p.mo) return mo < p.mo;
            if(en != p.en) return p.en < en;
            if(en == 1)
                return p.n < n;
            if(en == 0)
                return n < p.n;
        }
};

int main()
{
    data number[MX];

    int n, mod;

    while(scanf("%d %d", &n, &mod) == 2)
    {
        printf("%d %d\n", n, mod);
        if(n == 0 && mod == 0) return 0;
        int a;
        for(int i = 0; i < n; i++)
          {
              scanf("%d", &a);
              number[i] = data(a, mod);
          }

        sort(number, number+n);

        for(int i = 0; i < n; i++)
            printf("%d\n", number[i]);
    }
    return 0;
}
