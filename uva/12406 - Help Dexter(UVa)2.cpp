#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;

#define ll long long int

int last, t;
ll low, top;

void backtrack2(int pos, ll n)
{
    //printf("%d %d %d\n", pos, n, last);
    if(pos == last && (((ll)n%((ll)1<<t)) == 0))
    {
        if(top < n)
            top = n;
        if(low > n)
            low = n;
    }
    if(pos == last) return;
    backtrack2(pos+1,(ll)(n*10)+1);
    backtrack2(pos+1,(ll)(n*10)+2);
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "a", stdout);
    int p, q, te, ti;
    scanf("%d", &ti);
    for(te = 1; ti >= te; te++)
    {
        scanf("%d %d", &p, &q);
        printf("Case %d: ", te);
        top = -1, low = 999999999999999999LL;
        last = p;
        t = q;
        backtrack2(0,0);
        if(top == -1)
            printf("impossible\n");
        else if(top == low)
            printf("%lld\n", top);
        else
            printf("%lld %lld\n", low, top);
    }
    return 0;
}
