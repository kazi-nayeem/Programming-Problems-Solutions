#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int arr[2005];

int main()
{
    int te, ti, n, res;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr,arr+n);
        res = 0;
        for(int i = 2; i < n; i++)
        {
            for(int j = 0, k = i; j < i-1; j++)
            {
                int dif = arr[i]-arr[j];
                for(; ((k-1)>j)&&(arr[k-1] > dif);)
                        k--;
                if(k<j+1)
                k = j+1;
                if(arr[i] < arr[j]+arr[k])
                res += i-k;
                //printf("i=%d  j=%d  k=%d dif=%d\n", i, j, k, dif);
            }
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
