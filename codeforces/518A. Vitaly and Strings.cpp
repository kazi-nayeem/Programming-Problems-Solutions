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

char str1[2000];
char str2[2000];
char str3[2000];

void next_permutati(void)
{
    for(int i = strlen(str1)-1; i >= 0; i--)
    {
        if(str1[i] < 'z')
        {
            str1[i]++;
            break;
        }
        else str1[i] = 'a';
    }
}

int main()
{
    scanf(" %s %s", str1, str2);
    strcpy(str3,str1);
    int len = strlen(str1);
    next_permutati();
    //puts(str3);
    if(strcmp(str1,str2) >= 0 || strcmp(str1,str3) <= 0)
    {
        puts("No such string");
    }
    else
        puts(str1);
    return 0;
}


