#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    char name[12][15];
    map<string,int> mp;
    int taka[12];
    int member, mpc;
    char str[15];
    int gift, num, add;
    bool flag = false;
    while(scanf("%d", &member) == 1)
    {
        if(flag == true)
            putchar('\n');
        flag = true;
        mp.clear();
        memset(str, 0, sizeof (str));
        mpc = 0;
        for(int i = 0; i < member; i++)
        {
            scanf(" %s", str);
            if(mp.find(string(str)) == mp.end())
            {
                mp[str] = mpc;
                strcpy(name[mpc++],str);
            }
        }
        memset(taka,0,sizeof(taka));
        for(int i = 0; i < member; i++)
        {
            scanf(" %s %d %d", str, &gift, &num);
            if(num == 0)
                continue;
            taka[mp[str]] += (gift % num) - gift;
            add = gift / num;
            for(int j = 0; j < num; j++)
            {
                scanf(" %s", str);
                taka[mp[str]] += add;
            }
        }
        for(int i = 0;i < member; i++)
            printf("%s %d\n", name[i], taka[mp[string(name[i])]]);
    }
    return 0;
}
