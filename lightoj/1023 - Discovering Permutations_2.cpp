#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

char vc[27];
int flag[26];
int n, k, p;

void backtrack(int t);

int main()
{
    int ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %d %d", &n, &k);

        memset(vc, 0, sizeof vc);
        memset(flag, 0, sizeof flag);
        p = 0;

        printf("Case %d:\n", te);
        backtrack(0);
    }
    return 0;
}

void backtrack(int t)
{
    if(t == n)
    {
        puts(vc);
        p++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(flag[i] != 0) continue;

        vc[t] = i+'A';
        flag[i] = 1;
        backtrack(t+1);
        flag[i] = 0;
        if(p == k) return;
    }
    return;
}
