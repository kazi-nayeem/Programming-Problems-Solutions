#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 225

int n, printed;
int ind[27], flag[27];
char order[27];
vector<int > adj[27];

void backtrack(int de);

int main()
{
    char str[MX];
    int len, te, f, t;
    scanf("%d", &te);
    getchar();

    while(te--)
    {
        gets(str);
        gets(str);
        len = strlen(str);
        n = (len+1)/2;

        for(int i = 0; i < 27; i++)
        {
            ind[i] = -1;
            flag[i] = 1;
            adj[i].clear();
        }

        for(int i = 0; i < len;i+=2)
            ind[str[i]-'A'] = 0;

        gets(str);
        len = strlen(str);
        for(int i = 0; i < len; i+=4)
        {
            f = str[i] - 'A';
            t = str[i+2] - 'A';
            adj[f].push_back(t);
            ind[t]++;
        }
        printed = 1;
        backtrack(0);
        if(printed) puts("NO");
        if(te) putchar('\n');
    }
    return 0;
}

void backtrack(int de)
{
    if(de == n)
    {
        putchar(order[0]);
        for(int i = 1; i < n; i++)
        {
            putchar(' ');
            putchar(order[i]);
        }
        putchar('\n');
        printed = 0;
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(ind[i] == 0 && flag[i])
        {
            flag[i] = 0;
            order[de] = i+'A';
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

