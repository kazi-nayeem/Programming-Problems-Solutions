#include<cstdio>
#include<vector>
using namespace std;

#define MX 25

int cds[MX];
int max_sum, road, max_cd;
vector<int> next, maxi;

void backtrack(const int sum, const int n);

int main()
{
    int i, sz;

    while(scanf("%d %d", &road, &max_cd) == 2)
    {
        next.clear();
        maxi.clear();
        for(i = 0; i < max_cd; i++)
            scanf("%d", &cds[i]);
        max_sum = 0;
        backtrack(0,0);

        sz = (int) maxi.size();

        for(i = 0; i < sz; i++)
            printf("%d ", maxi[i]);
        printf("sum:%d\n", max_sum);
    }
    return 0;
}

void backtrack(const int sum, const int n)
{
    if(sum == road)
    {
        maxi.clear();
        maxi = next;
        max_sum = sum;
        return;
    }

    if(sum > max_sum)
    {
        maxi.clear();
        maxi = next;
        max_sum = sum;
    }

    for(int i = n; i < max_cd; i++)
    {
        if(sum+cds[i] <= road)
        {
            next.push_back(cds[i]);
            backtrack(sum+cds[i], i+1);
            next.pop_back();
        }
        if(road == max_sum) return;
    }
    return;
}
