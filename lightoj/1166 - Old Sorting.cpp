#include<cstdio>
#include<cstring>
using namespace std;

int arr[110];

int main()
{
    int n, te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", arr+i);
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] == i) continue;
            for(int j = i + 1; j<=n; j++)
                if(arr[j] == i)
            {
                arr[j] = arr[i];
                res++;
                break;
            }
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
