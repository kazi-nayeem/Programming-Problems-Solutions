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
#define MX 3005

int arr[MX];

vector<pair<int , int > > vc;

int main()
{
    int n, total;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    vc.clear();
    for(int i = 0; i < n; i++)
    {
        int k = i;
        for(int j= i+1; j < n; j++)
        {
            if(arr[j] < arr[k])
                k = j;
        }
        if(k == i) continue;
        int tem = arr[k];
        arr[k] = arr[i];
        arr[i] = tem;
        vc.push_back(make_pair(i,k));
    }
    printf("%d\n", vc.size());
    for(int i = 0; i < vc.size(); i++)
        printf("%d %d\n", vc[i].first, vc[i].second);
    return 0;
}
