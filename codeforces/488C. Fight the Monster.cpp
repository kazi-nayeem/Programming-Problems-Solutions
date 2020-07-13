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


int hpM,atkM,defM;

ll check(int hp, int atk, int def) {
    if(defM >= atk) return 100000000000ll;
    int di = max(0,atkM-def);
    int dim = atk-defM;
    int ti = (hpM+dim-1)/dim;
    return max(ti*di-hp+1,0);
}

int main() {
    ll ans = 100000000000000000ll;
    int hpY,atkY,defY;
    int h, a, d;
    scanf("%d %d %d", &hpY, &atkY, &defY);
    scanf("%d %d %d", &hpM, &atkM, &defM);
    scanf("%d %d %d", &h, &a, &d);
    for(int j = max(0,defM-atkY+1); j <= 200; j++)
        for(int k = 0; k <= 200; k++) {
            ans = min(ans,check(hpY,atkY+j,defY+k)*h+j*a+k*d);
        }
    printf("%d\n", ans);
    return 0;
}


