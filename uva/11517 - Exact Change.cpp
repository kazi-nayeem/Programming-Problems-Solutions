#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 20002

int arr[MX];
int coin[101];

int change(int pric, int n, int mx);

int main()
{
    //freopen("input.txt", "r", stdin);
    int price, n, maxi, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &price, &n);
        maxi = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", coin+i);
            maxi += coin[i];
        }
        maxi = min(maxi,MX-2);
        int k = change(price,n,maxi);
        printf("%d %d\n", k, arr[k]);
    }
}

int change(int pric, int n, int mx)
{
    for(int i = 1; i <= mx; i++)
        arr[i] = 200;
    arr[0] = 0;

    for(int i = 0; i < n; i++)
        for(int j = mx-coin[i]; 0 <= j; j--)
            arr[j+coin[i]] = min(arr[j+coin[i]],arr[j]+1);

    for(int i = pric; i <= mx; i++)
        if(arr[i] != 200) return i;

    return 0;
}
