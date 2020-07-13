#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100005

int arr[MX];

int main()
{
    int te, ti, mx, n;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        mx = -1;
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(int i = n; i > 0; i--)
        {
            if(arr[i]-arr[i-1] == mx)
                mx++;
            else if(arr[i]-arr[i-1] > mx)
                mx = arr[i]-arr[i-1];
        }
        printf("Case %d: %d\n", te, mx);
    }

    return 0;
}
