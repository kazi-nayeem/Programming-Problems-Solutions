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
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mat {
    int arr[3][3];
    mat operator * (const mat & p) const {
        mat R;    /// (B^P)%M
        memset(R.arr,0,sizeof R.arr);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++)
                    R.arr[i][j] += arr[i][k]*p.arr[k][j];
                R.arr[i][j] %= 2;
            }
        return R;
    }
};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
mat BigMod(mat B,ll P) {
    mat R;    /// (B^P)%M
    memset(R.arr,0,sizeof R.arr);
    for(int i = 0; i < 3; i++)
        R.arr[i][i] = 1;
    while(P>0) {
        if(P%2==1) {
            R=R*B;
        }
        P/=2;
        B=B*B;
    }
    return R;
}

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

int arr[2005][2005];

int fibo(ll n) {
    if(n == 1) return 1;
    if(n == 2) return 0;
    if(n == 3) return 1;
    mat B;
    memset(B.arr,0,sizeof B.arr);
    B.arr[0][0] = 1;
    B.arr[0][1] = 2;
    B.arr[0][2] = 3;
    B.arr[1][0] = 1;
    B.arr[2][1] = 1;
    mat res = BigMod(B,n-3);
    return (res.arr[0][0]+res.arr[0][2])%2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            arr[i][j] = fibo((ll) i*j*i*j);
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= n; j++)
//            printf("%d", arr[i][j]);
//        puts("");
//    }
    int cnt1 = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] != arr[j][n-i+1]) cnt1++;
        }
    //cout<<cnt1<<endl;
    int cnt2 = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] != arr[n-i+1][n-j+1]) cnt2++;
        }
    //cout<<cnt2<<endl;
    int cnt3 = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] != arr[j][n-i+1]) cnt3++;
        }
    //cout<<cnt3<<endl;
    for(int a0 = 0; a0 < q; a0++) {
        int angle;
        cin >> angle;
        // your code goes here
        if(angle%360 == 0) printf("0\n");
        else if(angle%360 == 90) printf("%d\n", cnt1);
        else if(angle%360 == 180) printf("%d\n", cnt2);
        else if(angle%360 == 270) printf("%d\n", cnt3);
    }
    return 0;
}


