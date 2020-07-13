#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int n, b;
    data(){}
    void ini(int a)
    {
        n = a;
        b = a & (-a);
    }
    bool operator < (const data & p) const
    {
        return b<p.b;
    }
};

data arr[100005];
vector<int> vc;

int main()
{
    int sum, lim;
    scanf("%d%d", &sum, &lim);
    for(int i = 1; i <= lim && sum; i++)
        arr[i].ini(i);
    sort(arr+1,arr+lim+1);
    for(int i = lim; i > 0 && sum > 0; i--)
    {
        if(arr[i].b <= sum)
        {
            vc.push_back(arr[i].n);
            sum -= arr[i].b;
        }
    }
    if(sum != 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", vc.size());
    for(int i = 0; i < vc.size(); i++)
        printf("%d ", vc[i]);
    puts("");
}
