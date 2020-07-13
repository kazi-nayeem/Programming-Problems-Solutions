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

bool check_prime(int n) {
    if(n == 1 || n == 4) return true;
    for(int i = 2; i < n; i++)
        if(n%i == 0) return false;
    return true;
}

ll BigMod(ll B,ll P,ll M) {
    ll R=1%M;    /// (B^P)%M
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

//int arr[MX];

int main() {
    int n;
    scanf("%d", &n);
    if(!check_prime(n)) {
        puts("NO");
        return 0;
    }
//    arr[1] = 1;
//    for(int i = 2; i < n; i++) {
//        arr[(i*BigMod(i-1,n-2,n))%n] = i;
//        //printf("%d ", (i*BigMod(i-1,n-2,n))%n);
//    }
    //puts("");
    puts("YES");
    printf("1");
    if(n == 4) {
        puts(" 3 2 4");
        return 0;
    }
    for(int i = 2; i <= n-1; i++) {
        printf(" %d", (i*BigMod(i-1,n-2,n))%n);
    }
    if(n > 1)
        printf(" %d", n);
    puts("");
    return 0;
}


