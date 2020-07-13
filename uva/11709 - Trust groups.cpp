///////////////////
//  Shamim Ehsan //
//  SUST CSE 12  //
//  2012331035   //
///////////////////
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#define PI (2* acos(0))
#define pb push_back
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int root;
char vis[1010];
vector<int>grid[1010];
vector<int>bg[1010];
typedef struct{
int st,end,node;
}ST;
ST arr[1010];
void dfs(int u)
{
    if(vis[u]==1)
    return ;
    vis[u]=1;
    arr[u].st=++root;
    for(int i=0;i<grid[u].size();i++)
    {
//        flag[root][grid[u][i]]=1;
        dfs(grid[u][i]);
    }
    arr[u].end=++root;
    arr[u].node=u;
    return;
}
void dfs2(int u)
{
    if(vis[u]==1)
    return ;
    vis[u]=1;
//    arr[u].st=root;
    for(int i=0;i<bg[u].size();i++)
    {
//        flag[root][grid[u][i]]=1;
        dfs2(bg[u][i]);
    }
//    arr[u].end=++root;
//    arr[u].node=u;
    return;
}
bool comp(ST a, ST b)
{
    return a.end>b.end;
}
int main()
{
    char str[150],str2[150];
    int n,m,num;
    map<string, int>mp;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0) return 0;
        getchar();
        for(int i=0;i<n;i++)
        {
            gets(str);
            mp[str]=i;
//            rev[i]=(string)str;
        }
        for(int i=0;i<m;i++)
        {
            gets(str);
            gets(str2);
            grid[mp[str]].pb(mp[str2]);
            bg[mp[str2]].pb(mp[str]);
        }
        root=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
        if(!vis[i])
            dfs(i);
        }
//        for(int i=0;i<n;i++)
//        {
//            printf("%d %d %d\n",arr[i].st,arr[i].end,arr[i].node);
//        }
        sort(arr,arr+n,comp);
        memset(vis,0,sizeof ( vis));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[arr[i].node])
            {
              ans++;
              dfs2(arr[i].node);
            }
        }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        printf("%d ",flag[i][j]);
//        puts("");
//    }
        printf("%d\n",ans);
    for(int i=0;i<n;i++)
    {
        grid[i].clear();
        bg[i].clear();
    }
    mp.clear();
    }
    return 0;
}
