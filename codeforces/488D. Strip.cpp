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

struct data1 {
    int num, pos;
    data1(int a, int b) {
        num = a;
        pos = b;
    }
    bool operator < (const data1 & p) const {
        return num>p.num;
    }
};

struct data2 {
    int num, pos;
    data2(int a, int b) {
        num = a;
        pos = b;
    }
    bool operator < (const data2 & p) const {
        return num<p.num;
    }
};

int dp[MX];
priority_queue<data1> min_val;
priority_queue<data2> max_val;
priority_queue<data1> ans;

int main() {
    int n, l, s;
    dp[0] = 0;
    int tail = 0;
    scanf("%d %d %d", &n, &s, &l);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        min_val.push(data1(x,i));
        max_val.push(data2(x,i));

        while(min_val.top().num + s < max_val.top().num) {

            if(min_val.top().pos < max_val.top().pos) {
                tail = min_val.top().pos;
            } else {
                tail = max_val.top().pos;
            }

            while(tail>= min_val.top().pos) min_val.pop();
            while(tail>= max_val.top().pos) max_val.pop();
        }
        if(i>=l) {
            ans.push(data1(dp[i-l],i-l));
            //printf("push %d %d\n", dp[i-l], i-l);
        }
        while(!ans.empty() && ans.top().pos < tail) ans.pop();

        if(!ans.empty()) {
            dp[i] = ans.top().num+1;
        }
        else
            dp[i] = 10000000;
        //printf("%d tail %d %d min %d mx %d\n", i, tail, dp[i], min_val.top().num, max_val.top().num);
    }
    if(dp[n] > n) dp[n] = -1;
    printf("%d\n", dp[n]);
    return 0;
}


