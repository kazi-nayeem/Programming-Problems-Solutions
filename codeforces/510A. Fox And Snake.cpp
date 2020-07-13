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

char str[55][55];

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    memset(str,'.', sizeof str);
    for(int i = 0; i < a; i+=2)
        for(int j = 0; j < b; j++)
            str[i][j] = '#';
    for(int i = 1; i < a; i+= 4)
        str[i][b-1] = '#';
    for(int i = 3; i < a; i+= 4)
        str[i][0] = '#';
    for(int i = 0; i < a; i++)
    {
        str[i][b] = 0;
        puts(str[i]);
    }
    return 0;
}
