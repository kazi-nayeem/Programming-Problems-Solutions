#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long

int arr[30005];

int main()
{
    int pos = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    sort(arr+1,arr+n+1);
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pos < arr[i])
            pos = arr[i];
        else
        {
            res += pos-arr[i]+1;
            pos++;
        }
    }
    printf("%d\n", res);
    return 0;
}

