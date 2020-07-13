#include <iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[100005];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr,arr+n);
    for(int i = 0; i < n; i++)
    {
        ans = max(ans,abs(arr[i].second-i)+1);
    }
    printf("%d\n", ans);
    return 0;
}
