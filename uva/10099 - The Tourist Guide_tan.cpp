#include<iostream>
#include<cstdio>
#include<cstring>
 #include<algorithm>
  #include<queue>
  #include<vector>
  #include<stack>
  #include<fstream>
  #define maxs 103
   using namespace std;
   struct edge { int u,v,w;

bool operator < (const edge &p) const
{ return w>p.w; }
};
int par[maxs];
 vector <edge> e;
 vector <edge> lists[maxs];

int finds(int r)
 {
     return ((par[r]==r)?r:(finds(par[r])));
      }
      void mst(int n)
       {
           sort(e.begin(),e.end());
           for(int i=0;i<=n;i++) par[i]=i;
           int count=0,s=-1;
            for(int i=0;i<e.size();i++)
                { int u=finds(e[i].u),v=finds(e[i].v);
                    if(u!=v)
                        {
                            par[u]=v;
count++;
edge get;
get.u=e[i].u;
get.v=e[i].v;
get.w=e[i].w;
lists[e[i].u].push_back(get);
get.v=e[i].u;
get.u=e[i].v;
get.w=e[i].w;
lists[e[i].v].push_back(get); if(count==n-1) break; } } return ; }
queue <int> qu;
char colour[maxs];
int dist[maxs];
void bfs(int root)
{
    colour[root]=1;
    qu.push(root);
    dist[root]=0;
    while(!qu.empty())
        {
            int r=qu.front();
qu.pop();
for(int i=0;i<lists[r].size();i++)
    { if(colour[lists[r][i].v]==1) continue; colour[lists[r][i].v]=1; dist[lists[r][i].v]=dist[r]+1; qu.push(lists[r][i].v); } }

} int main() { //freopen("/media/Others/input.txt","r",stdin); int nds,egs,sc=1; while(cin>>nds>>egs && (nds||egs)) { for(int i=0;i<egs;i++) { edge get; cin>>get.u>>get.v>>get.w; e.push_back(get); } mst(nds); int strt,stp,ppl; cin>>strt>>stp>>ppl; bfs(strt); stack <int > st; st.push(stp); int das=-1;

while(!st.empty()) { int r=st.top(); st.pop(); int dis=dist[r]; for(int i=0;i<lists[r].size();i++) { if(dist[lists[r][i].v]==dist[r]-1) { if(das==-1) das=lists[r][i].w; else if(das>lists[r][i].w) das=lists[r][i].w; st.push(lists[r][i].v); } }

} //cout<<das; das=das-1; int rpl=ppl/das,co=0;

if(ppl%das!=0) co++; co=co+rpl; printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",sc++,co); e.clear(); for(int i=0;i<=nds;i++) { lists[i].clear(); dist[i]=0; } memset(colour,0,sizeof colour); }

return 0; }
