//#include <bits/stdc++.h>

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
#include<map>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

vector<int> vc;

int main()
{
    vc.push_back(4);
    vc.push_back(7);
    vc.push_back(44);
    vc.push_back(47);
    vc.push_back(74);
    vc.push_back(77);
    vc.push_back(444);
    vc.push_back(447);
    vc.push_back(474);
    vc.push_back(477);
    vc.push_back(744);
    vc.push_back(747);
    vc.push_back(774);
    vc.push_back(777);
    int n;

    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i < vc.size(); i++)
    {
        if(n%vc[i] == 0) flag = true;
    }
    if(flag)
        puts("YES");
    else
        puts("NO");

    return 0;
}


