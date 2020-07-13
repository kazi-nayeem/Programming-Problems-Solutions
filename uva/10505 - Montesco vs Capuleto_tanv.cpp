#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
vector<int> lists[201];
map<int,int>mp;
char colour[201];
int count;
void bfs(int root)
{
    queue<int> qu;
    qu.push(root);
    colour[root]=1;
    while(!qu.empty())
    {
        int r=qu.front();
        qu.pop();
        for(int i=0;i<lists[r].size();i++)
        {
            if(colour[r]==colour[lists[r][i]])
            {
                count=1;
            }
            if(colour[lists[r][i]]!=0)
            continue;
            if(colour[r]==1)
            colour[lists[r][i]]=2;
            else
            colour[lists[r][i]]=1;
            qu.push(lists[r][i]);
        }
    }
}
int main()
{
    int lcks;
    while(cin>>lcks)
    for(int cses=0;cses<lcks;cses++)
    {
        int edges,zeros=0,ones=0,maxs=0;
        cin>>edges;
        for(int i=0;i<edges;i++)
        {
            int a;
            cin>>a;
            if(a>=1)
            {
                int c;
                for(int j=0;j<a;j++)
                {
                    cin>>c;
                    lists[i+1].push_back(c);
                    lists[c].push_back(i+1);
                }
            }
        }
        for(int col=1;col<=edges;col++)
        {
            if(colour[col]==0)
            {bfs(col);
            for(int i=1;i<=edges;i++)
            {
                if(colour[i]==1)
                {ones++;
                colour[i]=3;
                }
                else if(colour[i]==2)
                {zeros++;
                colour[i]=3;
                }
            }
            if(count==1)
            maxs=maxs;
            else
            maxs+=(zeros>ones)?zeros:ones;
            zeros=ones=0;
            count=0;
        }
        }
        for(int i=0;i<=200;i++)
        colour[i]=0;
        for(int i=0;i<=200;i++)
            lists[i].clear();
        cout<<maxs<<endl;
        maxs=0;
        count=0;
    }
    return 0;
}
