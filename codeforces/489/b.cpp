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

int flag[105];
int male[105];
int fema[105];

int main()
{
    int n, m, res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &male[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &fema[i]);
    sort(male, male+n);
    sort(fema, fema+m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(flag[j] == 0 && (abs(male[i]-fema[j]) <= 1))
            {
                flag[j] = 1;
                res++;
                break;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
