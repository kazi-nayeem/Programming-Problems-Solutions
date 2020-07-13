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
#define MX 5000006ll

ll arr[MX];

int main()
{
    for(ll i = 2; i < MX; i++)
    {
        if(arr[i] == 0)
        {
            for(ll j = i; j < MX; j *= i)
                for(ll k = j; k < MX; k += j)
                    arr[k]++;
        }
        arr[i] += arr[i-1];
    }
    int te;
    scanf("%d", &te);
    while(te--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%I64d\n", arr[a]-arr[b]);
    }
    return 0;
}
