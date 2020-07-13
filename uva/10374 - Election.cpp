#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    map<string,pair<string,int> > mp;
    vector <string> name;
    int time, flag = 0;
    scanf("%d", &time);
    getchar();
    while(time--)
    {
        if(flag)
            putchar('\n');
        flag = 1;
        getchar();
        mp.clear();
        name.clear();
        int member;
        scanf("%d", &member);
        getchar();
        char party[100];
        char temp[100];
        for(int i = 0; i < member; i++)
        {
            gets(temp);
            gets(party);
            mp[temp] = make_pair(party,i);
            name.push_back(temp);
        }
        int vote;
        scanf("%d", &vote);
        getchar();
        int total[25];
        memset(total,0,sizeof total);
        for(int i= 0; i < vote; i++)
        {
            gets(temp);
            if(mp.find(temp) != mp.end())
                total[mp[temp].second]++;
        }
        int tie = 0, maximum = 0;
        for(int i = 1; i < member; i++)
        {
            if(total[maximum] < total[i])
            {
                tie = 0;
                maximum = i;
            }
            else if(total[maximum] == total[i])
                tie = 1;
        }
        if(tie)
            printf("tie\n");
        else
            printf("%s\n", mp[name[maximum]].first.c_str());
    }
    return 0;
}
