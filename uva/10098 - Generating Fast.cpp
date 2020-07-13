#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<char> vc;
int flag[15];
char str[15];
int n;

void backtrack(int t);

int main()
{
    int ti;
    scanf("%d", &ti);
    gets(str);
    while(ti--)
    {
        gets(str);
        n = strlen(str);
        sort(str, str+n);
        vc.clear();
        memset(flag, 0, sizeof flag);

        backtrack(0);
        putchar('\n');
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

