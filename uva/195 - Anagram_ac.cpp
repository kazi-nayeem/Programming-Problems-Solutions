#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define MX 500

vector<char> vc;
int flag[MX];
char str[MX];
int n;

void backtrack(int t);

int comp(const void *a, const void *b)
{
    char m = *(int *) a;
    char n = *(int *) b;
    int c,d;

    if(m >= 'a')
        c = m - 'a';
    else
        c = m - 'A';

    if(n >= 'a')
        d = n - 'a';
    else
        d = n - 'A';

    if(c != d) return c - d;
    return m - n;

}
int main()
{
    int ti;
    scanf("%d", &ti);
    gets(str);
    while(ti--)
    {
        gets(str);
        n = strlen(str);
        qsort(str, n,sizeof (char), comp);
        vc.clear();
        memset(flag, 0, sizeof flag);

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
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(flag[i] != 0) continue;
        if(i > 0)
            if(str[i] == str[i-1] && flag[i-1] == 0) continue;
        vc.push_back(str[i]);
        flag[i] = 1;
        backtrack(t+1);
        flag[i] = 0;
        vc.pop_back();
    }
    return;
}
