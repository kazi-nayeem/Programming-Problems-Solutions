#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

#define MX 100005

map<int,int> mp;
int arr[MX];
int flag[MX];

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    mp.clear();
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        mp[arr[i]] = i;
    }
    bool ans = true;
    int k;
    memset(flag,-1,sizeof flag);
    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == -1)
        {
            if(mp.find(a-arr[i])!= mp.end())
            {
                k = mp[a-arr[i]];
                if(flag[k] == -1)
                {
                    flag[i] = 0;
                    flag[k] = 0;
                    continue;
                }
            }
            if(mp.find(b-arr[i])!= mp.end())
            {
                k = mp[b-arr[i]];
                if(flag[k] == -1)
                {
                    flag[i] = 1;
                    flag[k] = 1;
                    continue;
                }
            }
            ans = false;
            break;
        }
    }
    if(ans)
    {
        printf("YES\n%d", flag[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", flag[i]);
        puts("");
        return 0;
    }
    ans = true;
    memset(flag,-1,sizeof flag);
    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == -1)
        {
            if(mp.find(b-arr[i])!= mp.end())
            {
                k = mp[b-arr[i]];
                if(flag[k] == -1)
                {
                    flag[i] = 1;
                    flag[k] = 1;
                    continue;
                }
            }
            if(mp.find(a-arr[i])!= mp.end())
            {
                k = mp[a-arr[i]];
                if(flag[k] == -1)
                {
                    flag[i] = 0;
                    flag[k] = 0;
                    continue;
                }
            }
            ans = false;
            break;
        }
    }
    if(ans)
    {
        printf("YES\n%d", flag[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", flag[i]);
        puts("");
        return 0;
    }
    printf("NO\n");
    return 0;
}
