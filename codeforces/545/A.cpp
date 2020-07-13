#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int flag[10000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if(x == 0 || x == -1) continue;
            if(x == 1 || x == 3) flag[i] = 1;
            if(x == 2 || x == 3) flag[j] = 1;
        }
    int to = 0;
    for(int i = 0; i < n; i++)
        to += flag[i];
    printf("%d\n", n-to);
    for(int i = 0; i < n; i++)
        if(flag[i] == 0) printf("%d ", i+1);
    return 0;
}
