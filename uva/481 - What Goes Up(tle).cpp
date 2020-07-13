#include<cstdio>
#include<iostream>
using namespace std;

#define MX 100050

int arr[MX];
int value[MX];
int sequ[MX];

int lis(int n)
{
    int mx = -1;
    for(int i = 0; i < n; i++) value[i] = 1;

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j] && value[i]+1>value[j])
                value[j] = value[i]+1;
            if(mx<value[j])
                mx = value[j];
        }
    printf("%d\n-\n", mx);
    int te = mx;
    for(int i = n-1; i >= 0 && te > 0; i--)
        if(value[i] == te)
        {
            sequ[te] = arr[i];
            te--;
        }
    for(int i = 1; i <= mx; i++)
        printf("%d\n", sequ[i]);
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    while(scanf("%d", &arr[n++]) == 1);
    lis(n);
    return 0;
}
