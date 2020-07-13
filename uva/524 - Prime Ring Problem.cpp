#include<cstdio>
#include<vector>
using namespace std;

#define MX 18

vector<int> next;
int take[MX];
int prime[33];
int n;

void backtrack(void);
void sieve(void);

int main()
{
    sieve();
    next.push_back(1);
    take[1] = 1;
    int test = 0;
    while(scanf("%d", &n) == 1)
    {
        if(test)
            putchar('\n');
        printf("Case %d:\n", ++test);
        backtrack();
    }

    return 0;
}

void backtrack(void)
{
    int sz = (int) next.size();
    if(sz == n)
    {
        if(prime[next[0]+next[sz-1]] == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(i)
                    putchar(' ');
                printf("%d", next[i]);
            }
            putchar('\n');
        }
        return;
    }
    for(int i = 2; i <= n; i++)
    {
        if(take[i] == 0)
        {
            if(prime[next[sz-1]+i] == 0)
            {
                next.push_back(i);
                take[i] = 1;
                backtrack();
                take[i] = 0;
                next.pop_back();
            }
        }
    }
    return;
}

void sieve(void)
{
    for(int i = 4; i < 33; i+=2)
        prime[i] = 1;
    for(int i = 9; i<33; i+=6)
        prime[i] = 1;
    prime[15] = 1;
    prime[25] = 1;
    return;
}
