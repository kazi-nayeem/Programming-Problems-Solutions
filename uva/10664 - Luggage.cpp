#include<cstdio>
#include<cstring>
#include<sstream>
using namespace std;

int arr[22];
int dp[105];

int main()
{
    int n, total, div, ti;
    char str[1000];

    scanf(" %d", &ti);
    gets(str);
    while(ti--)
    {
        gets(str);
        stringstream ss(str);
        n = 0;
        total = 0;
        while(ss>>arr[n])
        {
            total += arr[n];
            n++;
        }
        if(total&1)
        {
            printf("NO\n");
            continue;
        }
        div = total >> 1;
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(dp[div - arr[i]] == 1)
            {
                arr[div] = 1;
                    break;
            }
            for(int j = div-1; j>=arr[i];j--)
                if(dp[j] == 0) dp[j] = dp[j-arr[i]];
        }
        if(arr[div] == 1) puts("YES");
        else puts("NO");
    }
    return 0;
}
