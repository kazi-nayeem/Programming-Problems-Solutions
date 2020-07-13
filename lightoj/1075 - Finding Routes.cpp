#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

int next[336];
int deg[336];
map<string,int> mp;
char str[336][15];

int main()
{
    int te, ti, s, pos, pos1, pos2;
    char str1[20], str2[20];
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &s);
        memset(deg,0,sizeof deg);
        memset(next,-1,sizeof next);
        mp.clear();
        pos = 1;
        for(int i = 1; i < s; i++)
        {
            scanf(" %s %s", str1, str2);
            if(mp.find((string) str1) == mp.end())
            {
                strcpy(str[pos],str1);
                pos1 = pos;
                mp[(string) str1] = pos++;
            }
            else pos1 = mp[str1];
            if(mp.find((string) str2) == mp.end())
            {
                strcpy(str[pos],str2);
                pos2 = pos;
                mp[(string) str2] = pos++;
            }
            else pos2 = mp[str2];
            deg[pos2]++;
            next[pos1] = pos2;
        }
        for(int i = 1; i <= s; i++)
            if(deg[i] == 0) pos = i;
        printf("Case %d:\n", te);
        for(int i = 0; i < s; i++)
        {
            puts(str[pos]);
            pos = next[pos];
        }
        puts("");
    }
    return 0;
}
