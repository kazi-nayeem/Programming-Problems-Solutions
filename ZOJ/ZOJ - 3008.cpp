#include<cstdio>
#include<map>
#include<vector>
using namespace std;

#define MX 10005
#define MXP 1229

int flag[MX];
int prime[MXP];

void sieve(void);

int main()
{
    map<int,int> mp;
    vector<int> vc, pr;
    sieve();

    int n, m, temp;
    while(scanf("%d%d", &n, &m) == 2)
    {
        mp.clear();
        vc.clear();
        pr.clear();

        int j = n;
        for(int i = 0; i < MXP&&j>=prime[i];)
        {
            if(j%prime[i] == 0)
            {
                //printf("%d\n", prime[i]);
                pr.push_back(prime[i]);
                j /= prime[i];
            }
            else i++;
        }

        vc.push_back(1);
        int sz = pr.size();
        for(int z = 0; z < m; z++)
        for(int i = 0; i < sz ; i++)
        {
            int szv = vc.size();
            for(int u = 0; u < szv; u++)
            {
                int t = vc[u]*pr[i];
                //printf("%d\n", t);
                if((t <= n) && (mp.find(t) == mp.end()))
                {
                    mp[t] = 1;
                    vc.push_back(t);
                }
            }
        }
        printf("%d\n", (int) vc.size());
    }

    return 0;
}

void sieve(void)
{
    int pos = 1;
    prime[0] = 2;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            prime[pos++] = i;
            int ad = i+i;
            for(int j = i*i; j < MX; j+= ad)
                flag[j] = 1;
        }
    }
    //printf("%d\n", pos);
    //for(int i = 0; i < 10; i++)
       // printf("%d\n", prime[i]);
    return;
}
