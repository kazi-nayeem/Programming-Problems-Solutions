#include<cstdio>
using namespace std;

int main()
{
    int arr[10005], time, test, n, i;
    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d %d %d %d %d %d", arr+0, arr+1, arr+2, arr+3, arr+4, arr+5, &n);

        for(i = 0; i < 6; i++)
            arr[i] %= 10000007;
        for(i = 6; i <= n; i++)
            arr[i] = (arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6]) % 10000007;
        printf("Case %d: %d\n", test, arr[n]);
    }
    return 0;
}
