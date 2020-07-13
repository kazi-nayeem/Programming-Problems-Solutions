#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;

#define ll long long int

ll high[20];
//ll low[20];
int last, t;
ll top;

void backtrack(int pos, ll n)
{
    //printf("%d %d\n", pos, n);
    if(((ll)n%((ll)1<<pos)) == 0)
    {
        if(high[pos] < n) high[pos] = n;
        //if(low[pos] > n) low[pos] = n;
    }
    if(pos == 18) return;
    backtrack(pos+1,(ll)(n*10)+1);
    backtrack(pos+1,(ll)(n*10)+2);
    return;
}

void backtrack2(int pos, ll n)
{
    //printf("%d %d %d\n", pos, n, last);
    if(pos == last && (((ll)n%((ll)1<<t)) == 0))
    {
        top = n;
        //if(low[pos] > n) low[pos] = n;
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
    //for(int i = 0; i < 20; i++)
    //low[i] = 5042304000000000000LL;
    last = 18;
    backtrack(0,0);
    //for(int i = 0; i < 20; i++)
    //printf("%d %lld\n", i, high[i]);
    int p, q, te, ti;
    scanf("%d", &ti);
    for(te = 1; ti >= te; te++)
    {
        scanf("%d %d", &p, &q);
        printf("Case %d: ", te);
        if(p == q)
            printf("%lld\n", high[p]);
        else if(p < q)
        {
            last = p;
            t = q;
            top = 0;
            backtrack2(0,0);
            if(top == 0)
                printf("impossible\n");
            else
                printf("%lld\n", top);
        }
        else
        {
            for(int i = q; i < p; i++)
                putchar('1');
            if(q>0)
                printf("%lld", high[q]);
            putchar(' ');
            for(int i = q; i < p; i++)
                putchar('2');
            if(q > 0)
                printf("%lld", high[q]);
            putchar('\n');
        }
    }
    return 0;
}
