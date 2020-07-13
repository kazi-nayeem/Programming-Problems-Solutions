#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int arr[25005];
int coin[105];

int main()
{
    int n, total, div, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", coin+i);
            total += coin[i];
        }
        int maxi = 0;
        div = total / 2;
        for(int i = 0; i <= div; i++) arr[i] = 0;
        arr[0] = 1;
        for(int i = 0; i < n; i++)
        {
            maxi = min(maxi+coin[i],div);
            for(int j = maxi; j >= coin[i]; j--)
            {
                if(arr[j-coin[i]] == 1)
                    arr[j] = 1;
            }
        }
        for(int i = div; i >= 0; i--)
        {
            if(arr[i] == 1)
            {
                printf("%d\n", total - i - i);
                break;
            }
        }
    }
    return 0;
}
