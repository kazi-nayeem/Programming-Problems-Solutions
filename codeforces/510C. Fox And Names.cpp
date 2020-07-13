#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long

int deg[100];
vector<int> adj[100];
char str[105][105];
vector<int> res;

void solve()
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(deg[j] == 0)
            {
                res.push_back(j);
                deg[j]--;
                for(int k = 0; k < adj[j].size(); k++)
                    deg[adj[j][k]]--;
                break;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf(" %s", str[i]);
    }
    for(int i = 0; i < num; i++)
        for(int j = i+1; j < num; j++)
        {
            int len1 = strlen(str[i]);
            int len2 = strlen(str[j]);
            int k;
            for(k = 0; k < min(len1,len2); k++)
            {
                if(str[i][k] != str[j][k])
                {
                    adj[str[i][k]-'a'].push_back(str[j][k]-'a');
                    deg[str[j][k]-'a']++;
                    break;
                }
            }
            if((k == min(len1,len2)) && len1 > len2)
            {
                puts("Impossible");
                return 0;
            }
        }
    solve();
    if(res.size() != 26)
    {
        puts("Impossible");
        return 0;
    }
    for(int i = 0; i < 26; i++)
        printf("%c", res[i]+'a');
    puts("");
    return 0;
}

