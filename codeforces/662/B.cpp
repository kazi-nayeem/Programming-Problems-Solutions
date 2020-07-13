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

int arr[MX];

struct data1{
    int pos, num;
    data1(int a, int b):pos(a),num(b){}
    bool operator < (const data1 & p) const{
        if(p.num != num) return num < p.num;
        return pos>p.pos;
    }
};

struct data2{
    int pos, num;
    data2(int a, int b):pos(a),num(b){}
    bool operator < (const data2 & p) const{
        if(p.num != num) return num > p.num;
        return pos>p.pos;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    int mx = 0;
    priority_queue<data1> qu;
    priority_queue<data2> qu2;
    int pre = 0;
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        qu.push(data1(i,x));
        qu2.push(data2(i,x));
        while(qu.top().num > x+1 || qu.top().pos < pre) {
                pre = max(pre,qu.top().pos);
                qu.pop();
        }
        while(qu2.top().num < x-1 || qu2.top().pos < pre) {
                pre = max(pre,qu2.top().pos);
                qu2.pop();
        }
        //printf("%d %d\n", qu.top().pos, qu2.top().pos);
        mx = max(mx,i-pre);
    }
    printf("%d\n", mx);
    return 0;
}


