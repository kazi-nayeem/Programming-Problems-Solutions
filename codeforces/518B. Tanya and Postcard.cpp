#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long

int save[1000];
int nex[1000];
char str1[200500];
char str2[200500];

int main()
{
    //printf("%d\n", 'A' - 'a');
    scanf(" %s %s", str1, str2);
    int len1 = strlen(str1);
    for(int i = 0; i < len1; i++)
        save[str1[i]]++;

    int len2 = strlen(str2);
    for(int i = 0; i < len2; i++)
        nex[str2[i]]++;

    int res1 = 0, res2 = 0;

    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(save[i] <= nex[i])
        {
            res1 += save[i];
            nex[i] -= save[i];
            save[i] = 0;
        }
        else
        {
            res1 += nex[i];
            save[i] -= nex[i];
            nex[i] = 0;
        }
    }

    for(int i = 'a'; i <= 'z'; i++)
    {
        if(save[i] <= nex[i])
        {
            res1 += save[i];
            nex[i] -= save[i];
            save[i] = 0;
        }
        else
        {
            res1 += nex[i];
            save[i] -= nex[i];
            nex[i] = 0;
        }
    }

    for(int i = 'a'; i <= 'z'; i++)
    {
        if(save[i] <= nex[i-32])
        {
            res2 += save[i];
            nex[i-32] -= save[i];
            save[i] = 0;
        }
        else
        {
            res2 += nex[i-32];
            save[i] -= nex[i-32];
            nex[i-32] = 0;
        }
    }
    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(save[i] <= nex[i+32])
        {
            res2 += save[i];
            nex[i+32] -= save[i];
            save[i] = 0;
        }
        else
        {
            res2 += nex[i+32];
            save[i] -= nex[i+32];
            nex[i+32] = 0;
        }
    }
    printf("%d %d\n", res1, res2);
    return 0;
}

