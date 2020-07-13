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

int mat[1020][1020];
vector<int> vc;

int findsum()
{
    int sum;
    for(int i = 0; i < vc.size(); i++)
        sum += mat[i][vc[i]];
    return sum;
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
        vc.clear();
        for(int i = 0; i < n; i++)
            vc.push_back(i);
        int sumto = findsum();
        bool flag = true;
        for(int i = 0; i < 2000; i++)
        {
            random_shuffle(vc.begin(),vc.end());
            if(sumto != findsum())
            {
                flag = false;
                break;
            }
        }
        if(flag)
            puts("homogeneous");
        else
            puts("not homogeneous");
    }
    return 0;
}

