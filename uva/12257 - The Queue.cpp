#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 225

int n, total;
int ind[MX], flag[MX];
vector<int> adj[MX];

void backtrack(int de);

int main()
{
    char str[MX];
    int len, te = 0, f, t;
    while(gets(str))
    {
        if(te) putchar('\n');
        te = 1;
        len = strlen(str);
        n = (len+1)/2;

        for(int i = 0; i < MX; i++)
        {
            ind[i] = -1;
            flag[i] = 1;
            adj[i].clear();
        }

        for(int i = 0; i < len;i+=2)
            ind[str[i]-'a'] = 0;

        gets(str);
        len = strlen(str);
        for(int i = 0; i < len; i+=4)
        {
            f = str[i] - 'a';
            t = str[i+2] - 'a';
            adj[f].push_back(t);
            ind[t]++;
        }
        backtrack(0);
    }
    return 0;
}

void backtrack(int de)
{
    if(de == n)
    {
        order[n] = '\0';
        puts(order);
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(ind[i] == 0 && flag[i])
        {
            flag[i] = 0;
            order[de] = i+'a';
            for(int j = 0; j < adj[i].size(); j++)
                ind[adj[i][j]]--;

            backtrack(de+1);

            for(int j = 0; j < adj[i].size(); j++)
                ind[adj[i][j]]++;
            flag[i] = 1;
        }
    }
    return;
}
