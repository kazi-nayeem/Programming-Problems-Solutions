#include<cstdio>
#include<set>
#include<map>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define ll long long

int xx[705];
int yy[705];
int res[30002];
int arr[244655];

int main()
{
    for(int i = 0; i <= 30000; i++) res[i] = i*i;
    int te, ti, n, pos, re;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        pos = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &xx[i], &yy[i]);
            for(int j = 0; j < i; j++)
                arr[pos++] = (res[abs(xx[i]-xx[j])]+res[abs(yy[i]-yy[j])]);
        }
        arr[pos] = -1;
        sort(arr,arr+pos+1);
        re = 1;
        for(int i = 1; i <= pos; i++)
            if(arr[i] != arr[i-1]) re++;
        printf("Case %d: %d\n", te, re);
    }
    return 0;
}
