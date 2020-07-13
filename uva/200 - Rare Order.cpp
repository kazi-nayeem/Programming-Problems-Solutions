#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int ind[26];
vector<int> adj[28];

void topsort(void);

int main()
{
    //freopen("input.txt", "r", stdin);
    char str1[28], str2[28], ch1, ch2;
    int len1, len2;
    while(gets(str1))
    {
        for(int i = 0; i < 26; i++) ind[i] = -1;

        len1 = strlen(str1);
        for(int i = 0; i < len1; i++) ind[str1[i]-'A'] = 0;
        while(gets(str2))
        {
            if(str2[0] == '#') break;
            len2 = strlen(str2);
            for(int i = 0; i < len2; i++) if(ind[str2[i]-'A'] == -1) ind[str2[i]-'A'] = 0;
            for(int i = 0; i < len2 && i < len1; i++)
            {
                if(str1[i] != str2[i])
                {
                    ind[str2[i]-'A']++;
                    adj[str1[i]-'A'].push_back(str2[i]-'A');
                    break;
                }
            }
            for(int i = 0; i <= len2; i++)
                str1[i] = str2[i];
            len1 = len2;
        }
        topsort();
    }
    return 0;
}

void topsort(void)
{
    queue<int> qu;
    for(int i = 0; i < 26; i++) if(ind[i] == 0) qu.push(i);

    while(!qu.empty())
    {
        int k = qu.front();
        qu.pop();

        putchar('A'+k);
        int sz = adj[k].size();
        for(int i = 0; i < sz; i++)
        {
            if(ind[adj[k][i]] == 1) qu.push(adj[k][i]);
            else
                ind[adj[k][i]]--;
        }
    }
    putchar('\n');
    return;
}
