#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char str1[MX];
char str2[MX];
char str[MX];

int main()
{
    gets(str1);
    gets(str2);
    int len = strlen(str1);
    int to = 0;
    for(int i = 0; i < len; i++)
    {
        if(str1[i] != str2[i]) to++;
    }
    if(to %2 != 0)
    {
        puts("impossible");
        return 0;
    }
    for(int i = 0; i < len; i++)
    {
        str[i] = str1[i];
        if(str1[i] == str2[i]) continue;
        if(to %2 == 0)
            str[i] = str2[i];
        to--;
    }
    puts(str);
    return 0;
}
