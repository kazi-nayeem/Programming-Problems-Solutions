#include<cstdio>
#include<algorithm>
using namespace std;

int arr[50005];

int main()
{
    int n, w, te, ti, total;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &w);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &total, &arr[i]);
        sort(arr, arr+n);
        total = 0;
        for(int i = 0; i < n; total++)
        {
            int mx = arr[i]+w;
            for(i++; arr[i] <= mx && i < n; i++);
        }
        printf("Case %d: %d\n", te, total);
    }

    return 0;
}
