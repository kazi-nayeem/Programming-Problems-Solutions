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


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 5761559
#define MX2 100000104
#define MX3 100000050
#define inf 100000000

const ll mod = 1000000007ll;
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/*
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

char flag[(MX2/8)];
int prime[MX];
int totprime;

int getbit(ll i)
{
    return (flag[i>>3]>>(i&7))&1;
}

void setbit(int i)
{
    flag[i>>3] |= 1<<(i&7);
}

void sieve()
{
    prime[0] = 2;
    totprime = 1;
    for(ll i = 3; i < MX3; i+=2)
    {
        if(getbit(i)) continue;
        prime[totprime++] = i;
        for(ll j = i*i; j < MX3; j+=i<<1)
        {
            setbit(j);
        }
    }
    //printf("%d\n", totprime);
//    for(int i = 0; i < 100; i++)
//        printf("%d %d\n", i, prime[i]);
}

bool isPrime(ll a)
{
    if(a == 2) return true;
    if(a < 2) return false;
    if(a<MX3)
    {
        if(a%2 == 0) return false;
        if(getbit(a)) return false;
        return true;
    }
    return Miller(a,1000);
    for(int i = 0; i < totprime; i++)
    {
        ll s = (ll) prime[i]*prime[i];
        if(a<s) break;
        if(a%prime[i] == 0) return false;
    }
    return true;
}

//Main
ll arr[MX];

int main()
{
    sieve();
    int ti, te, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        ll gcd = 0;
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            if(arr[i] > 1)
                gcd = __gcd(gcd,arr[i]);
            else
                flag = false;
        }
        printf("Case %d: ", te);
        if(n == 1)
        {
            printf("Can\'t decrypt\n");
            continue;
        }
        if(gcd<=1 || (!flag))
        {
            printf("Invalid message\n");
            continue;
        }
        for(int i = 1; i <= n && flag; i++)
        {
            arr[i] /= gcd;
            flag &= isPrime(arr[i]);
        }
        if(!flag)
        {
            puts("Invalid message");
            continue;
        }
        printf("%lld", arr[1]);
        for(int i = 2; i <= n; i++)
            printf(" %lld", arr[i]);
        puts("");
    }
//    int iteration = 5;
//    ll num;
//    cout<<"Enter integer to test primality: ";
//    cin>>num;
//    if (Miller(num, iteration))
//        cout<<num<<" is prime"<<endl;
//    else
//        cout<<num<<" is not prime"<<endl;
    return 0;
}

