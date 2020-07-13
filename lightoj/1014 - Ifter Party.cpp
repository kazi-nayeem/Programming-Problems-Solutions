#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    //freopen("output.txt", "w", stdout);
    vector<int> vc;
    int tes, tim, l, p, flag;
    scanf("%d", &tim);
    for(tes = 1; tes <= tim; tes++)
    {
        vc.clear();
        scanf("%d %d", &p, &l);
        printf("Case %d:", tes);
        p -= l;

        int roo = (int) sqrt(p);
        for(int i = 1; i <= roo; i++)
        {
            if(p % i == 0)
            {
                vc.push_back(i);
                if(i*i == p) continue;
                vc.push_back(p/i);
            }
        }

        sort(vc.begin(), vc.end());

        int sz = vc.size();
        flag = 1;

        for(int i = 0; i < sz; i++)
        {
            if(vc[i] > l)
            {
                printf(" %d", vc[i]);
                flag = 0;
            }
        }
        if(flag) printf(" impossible");
        putchar('\n');
    }
    return 0;
}
