#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int arr[10005];

int main()
{
    int m, n, t;
    while(scanf("%d %d %d", &m, &n, &t) == 3)
    {
        memset(arr, -1, sizeof arr);
        arr[0] = 0;
        for(int i = m; i <= t; i+=m)
            arr[i] = arr[i-m]+1;
        for(int i = n; i <= t; i++)
        {
            int k = i - n;
            if(arr[k] == -1) continue;
            arr[i] = max(arr[i],arr[k]+1);
        }
        if(arr[t] != -1)
            printf("%d\n", arr[t]);
        else
        {
            for(int i = t-1; i >= 0; i--)
            {
                if(arr[i] != -1)
                {
                    printf("%d %d\n", arr[i], t - i);
                    break;
                }
            }
        }
    }
    return 0;
}
