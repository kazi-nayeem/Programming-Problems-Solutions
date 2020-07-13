#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map<string,int> mp;
    char party[25][100];
    int total[25];
    int time;
    scanf(" %d", &time);
    getchar();
    while(time--)
    {
        mp.clear();
        getchar();
        int member;
        scanf(" %d", &member);
        getchar();
        for(int i = 0; i <= member; i++)
            total[i] = 0;
        char temp[100];
        for(int i = 1; i <= member; i++)
        {
            gets(temp);
            mp[temp] = i;
            gets(party[i]);
            //if(party[i][0] == '\0')
                //strcpy(party[i], "independent");
        }
        int vote;
        scanf(" %d", &vote);
        getchar();
        while(vote--)
        {
            gets(temp);
            if(mp.find(temp) != mp.end())
                total[mp[temp]]++;
        }
        int maximum = 1, tie = 0;
        for(int i = 2; i <= member; i++)
        {
            if(total[i] > total[maximum])
            {
                tie = 0;
                maximum = i;
            }
            else if(total[i] == total[maximum])
            {
                tie = 1;
            }
        }
        if(tie)
            puts("tie");
        else
            printf("%s\n" ,party[maximum]);
        if(time)
            putchar('\n');
    }
    return 0;
}
