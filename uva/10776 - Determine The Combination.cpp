#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<char> vc;
char str[35];
int flag[35];
int n, p;

void backtrack(int t, int pos);

int main()
{
    while(scanf(" %s %d", str, &p) == 2)
    {
        n = strlen(str);
        sort(str, str+n);
        vc.clear();
        memset(flag, 0, sizeof flag);

        backtrack(0, 0);
    }
    return 0;
}

void backtrack(int t, int pos)
{
    if(t == p)
    {
        for(int i = 0; i < t; i++)
            putchar(vc[i]);
        putchar('\n');
        return;
    }
    for(int i = pos; i < n; i++)
    {
        if(i > 0)
            if(str[i] == str[i-1] && flag[i-1] == 0) continue;
        vc.push_back(str[i]);
        flag[i] = 1;
        backtrack(t+1, i+1);
        flag[i] = 0;
        vc.pop_back();
    }
    return;
}


