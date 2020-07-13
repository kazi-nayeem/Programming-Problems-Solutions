#include<cstdio>
#include<algorithm>
using namespace std;

int arr[51];

int main()
{
    int te, ti;
    int n, total;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        total = 0;
        arr[n] = -1;
        for(int i = 0; i < n; i++)
        {
            int j;
            for(j = 1; i+j<n && j <= arr[i]; j++)
            {
                if(arr[i] != arr[i+j]) break;
            }
            i += j-1;
            total += arr[i]+1;
        }
        printf("Case %d: %d\n", te, total);
    }
    return 0;
}
