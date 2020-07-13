#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

char str[2][100];
map<int,bool> mp[2];

int main()
{
    scanf("%s%s", str[0], str[1]);
    int n, t, tim, mem;
    char tm, cr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %c %d %c", &tim, &tm, &mem,&cr);
        t = (tm == 'h')? 0:1;
        if(cr == 'r')
        {
            if(mp[t].find(mem) == mp[t].end() || mp[t][mem])
                printf("%s %d %d\n", str[t], mem, tim);
            mp[t][mem] = false;
        }
        else
        {
            if(mp[t].find(mem) == mp[t].end())
                mp[t][mem] = true;
            else
            {
                if(mp[t][mem])
                    printf("%s %d %d\n", str[t], mem, tim);
                mp[t][mem] = false;
            }
        }
    }
    return 0;
}
