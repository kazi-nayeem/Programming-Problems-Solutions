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

int a[100];
int s1[100];
int s2[100];
int n2, by;

int divi(int p) {
    int pre = 0;
    for(int i = 0; i < n2; i++) {
        pre *= by;
        pre += s2[i];
        pre %= p;
    }
    return pre;
}

int main() {
    int n1, bx;

    scanf("%d %d", &n1, &bx);
    for(int i = 0; i < n1; i++)
        scanf("%d", &s1[i]);
    scanf("%d %d", &n2, &by);
    for(int i = 0; i < n2; i++)
        scanf("%d", &s2[i]);
    int pos = 0;
    for(int i = 0; i < n1; i++) {
        int res = divi(bx,by);
        a[pos++] = res;
    }
    return 0;
}


