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

char str[200];
char str2[200];

int main()
{
    memset(str,0,sizeof str);
    int m, s;
    scanf("%d%d", &m, &s);
    if(m == 1 && s == 0)
    {
        printf("0 0\n");
        return 0;
    }
    if(s == 0 || (m*9 < s))
    {
        printf("-1 -1\n");
        return 0;
    }
    int k = 0;
    int sum = s;
    for(int i = 0; i < m; i++)
    {
        if(s>=9)
        {
            str[i] = '9';
            s -= 9;
        }
        else if(s > 0)
        {
            str[i] = '0'+ s;
            s = 0;
        }
        else
            str[i] = '0';
    }
    for(int i = m-1; i >= 0; i--)
    {
        str2[i] = str[m-i-1];
        if(str2[i] != '0') k = i;
    }
    str[m] = 0;
    str2[m] = 0;
    if(k != 0)
    {
        str2[0] = '1';
        str2[k]--;
    }
    printf("%s %s\n", str2, str);
    return 0;
}
