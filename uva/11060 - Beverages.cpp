#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MX 105

vector<int> order;
vector<int> co[MX];
int indegree[MX];

void sortorder(int work);

int main()
{
    //freopen("input.txt", "r", stdin);
    char name[105][55];
    char temp1[55], temp2[55];
    map<string, int> mp;
    int work, connect, sz, test = 1;

    while(scanf("%d", &work) == 1)
    {
        getchar();
        for(int i= 0; i <= work; i++)
            co[i].clear();
        memset(indegree, 0, sizeof indegree);
        mp.clear();

        for(int i = 0; i < work; i++)
        {
            gets(name[i]);
            mp[name[i]] = i;
        }
        scanf("%d", &connect);
        for(int i=0; i < connect; i++)
        {
            scanf("%s %s", temp1, temp2);
            co[mp[temp1]].push_back(mp[temp2]);
            indegree[mp[temp2]]++;
        }
        //for(int i = 0; i < work; i++)
            //printf("%d\n", indegree[i]);
        sortorder(work);

        sz = order.size();
        printf("Case #%d: Dilbert should drink beverages in this order:", test++);
        for(int i = 0; i < sz; i++)
            printf(" %s", name[order[i]]);
        printf(".\n\n");
    }
    return 0;
}

void sortorder(int work)
{
    order.clear();
    for(int i = 0; i < work;)
    {
        for(int j = 0; j < work; j++)
        {
            if(indegree[j] == 0)
            {
                order.push_back(j);
                i++;
                indegree[j] = -1;
                int sz = co[j].size();
                for(int k = 0; k < sz; k++)
                    indegree[co[j][k]]--;
                break;
            }
        }
    }
    return;
}

