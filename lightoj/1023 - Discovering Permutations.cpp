#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<char> vc;
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

        vc.clear();
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
        for(int i = 0; i < t; i++)
            putchar(vc[i]);
        putchar('\n');
        p++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(flag[i] != 0) continue;

        vc.push_back(i+'A');
        flag[i] = 1;
        backtrack(t+1);
        flag[i] = 0;
        vc.pop_back();
        if(p == k) return;
    }
    return;
}
