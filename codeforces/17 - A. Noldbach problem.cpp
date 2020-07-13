#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 1005

vector<int> prime;
int flag[MX];
int count[MX];

void sieve(void);

int main()
{
    sieve();
    int sz = prime.size();
    for(int i = 1; i < sz; i++)
    {
        int te = prime[i-1] + prime[i]+1;
        if(te <= 1000)
        if(flag[te] == 0)
        count[te] = 1;
    }

    for(int i = 3; i <= 1000; i++)
        count[i] += count[i-1];

    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        if(count[n] >= k)
        printf("YES\n");
        else
        printf("NO\n");
    }
}

void sieve(void)
{
    prime.push_back(2);
    for(int i = 4; i < MX; i+=2)
        flag[i] = 1;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            prime.push_back(i);
            int ad = i + i;
            for(int j = i * i; j < MX; j+= ad)
                flag[j] = 1;
        }
    }
    return;
}
