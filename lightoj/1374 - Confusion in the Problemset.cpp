#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

#define MX 5005
int arr[MX];

int main()
{
    int te, ti, n, x, di;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        di = (n+1)/2;
        bool flag = true;
        memset(arr,0,sizeof arr);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(x >= n)
                flag = false;
            else
            {
                if(1+x <= di)
                    arr[1+x]++;
                if(n-x<=di)
                    arr[n-x]++;
            }
        }
        if(flag)
        {
            for(int i = 1; i <= di; i++)
                if(arr[i] != 2) flag = false;
        }
        printf("Case %d: ", te);
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
