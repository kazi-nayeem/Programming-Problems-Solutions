#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MX 10005

int arr[MX];

int binary(const int n, const int fi);

int main()
{
    int n, total, cost, pos;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        sort(arr, arr+n);

        scanf("%d", &total);

        pos = binary(n-1, total/2);
        int i = pos, j = pos + 1;

        for(cost = arr[i]+arr[j]; cost != total;cost = arr[i]+arr[j])
        {
            if(cost > total)
            {
                if(i > 0)
                    i--;
                else
                    j--;
            }
            else
            {
                if(j+1 < n)
                    j++;
                else
                    i++;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", arr[i], arr[j]);
    }
    return 0;
}

int binary(const int n, const int fi)
{
    int beg = 0, en = n - 1, mid = en/2;
    for(;beg <= en; mid = (beg+en)/2)
    {
        if(arr[mid] == fi) return mid;
        if(arr[mid] > fi)
            en = mid -1;
        else
            beg = mid + 1;
    }
    return mid;
}
