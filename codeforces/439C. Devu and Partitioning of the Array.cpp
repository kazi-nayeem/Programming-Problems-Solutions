#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

#define MX 100005

typedef long long ll;

vector<int> odd;
vector<int> even;

int main()
{
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(x%2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    int s1 = even.size();
    int s2 = odd.size();
    if(s2 < k-p || (s2-k+p)%2 == 1 ||  (s2-k+p)/2 + s1 < p)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    if(p == 0)
    {
        for(int i = 0; i < k-1; i++)
            printf("1 %d\n", odd[i]);
        printf("%d", n-k+1);
        for(int i = k-1; i < odd.size(); i++)
            printf(" %d", odd[i]);
        for(int i = 0; i < even.size(); i++)
            printf(" %d", even[i]);
        puts("");
        return 0;
    }
    for(int i = 0; i < k-p; i++)
        printf("1 %d\n", odd[i]);
    int pri = k-p;
    for(int i = 0, j = k-p; i < p-1 && j < odd.size(); j+=2,i++)
    {
        printf("2 %d %d\n", odd[j], odd[j+1]);
        pri++;
    }
    int odp = 2*pri-k+p;
    int evp = k-pri-1;
    for(int i = 0; pri+1 < k; pri++, i++)
        printf("1 %d\n", even[i]);
    if(n-odp-evp == 0) return 0;
    printf("%d", n-odp-evp);
    for(int i = evp; i < even.size(); i++)
        printf(" %d", even[i]);
    for(int i = odp; i < odd.size(); i++)
        printf(" %d", odd[i]);
    puts("");
    return 0;
}

