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

vector<int> adj[10];

int main()
{
    adj[2].push_back(2);

    adj[3].push_back(3);

    adj[4].push_back(2);
    adj[4].push_back(2);
    adj[4].push_back(3);

    adj[5].push_back(5);

    adj[6].push_back(3);
    adj[6].push_back(5);

    adj[7].push_back(7);

    adj[8].push_back(2);
    adj[8].push_back(2);
    adj[8].push_back(2);
    adj[8].push_back(7);

    adj[9].push_back(2);
    adj[9].push_back(3);
    adj[9].push_back(3);
    adj[9].push_back(7);

    /*for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
            printf("%d ", adj[i][j]);
        puts("");
    }*/

    char str[100];
    vector<int> res;
    int n;
    scanf("%d", &n);
    scanf(" %s", str);
    //puts(str);
    for(int i = 0; i < n; i++)
    {
        int di = str[i]-'0';
        //printf("%d\n", di);
        for(int j = 0; j < adj[di].size(); j++)
            res.push_back(adj[di][j]);
    }
    sort(res.begin(),res.end());
    for(int i = res.size()-1; i >= 0; i--)
     printf("%d", res[i]);
    puts("");
    return 0;
}

