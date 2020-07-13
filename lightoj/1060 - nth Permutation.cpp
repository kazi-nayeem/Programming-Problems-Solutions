#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;

#define ll long long

int arr[26], len;
int num[25], last;
char ch[25];
ll fact[22];
char res[100];
char str[100];

int main()
{
    fact[0] = 1;
    for(int i = 1; i <= 20; i++)
        fact[i] = (ll) fact[i-1]*i;
    int te, ti;
    ll n;

    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%s%lld", str, &n);
        len = strlen(str);
        memset(arr,0,sizeof arr);
        for(int i = 0; i < len; i++)
            arr[str[i]-'a']++;
        last = 0;
        for(int i = 0; i < 26; i++)
            if(arr[i])
            {
                ch[last] = i+'a';
                num[last] = arr[i];
                last++;
            }
        ll tem = 1, total;
        for(int i = 0; i < last; i++)
            tem *= fact[num[i]];
        //printf("%lld\n", tem);
        if(fact[len]/tem < n)
        {
            printf("Case %d: Impossible\n", te);
            continue;
        }
        ll now;
        for(int i = 0; i < len; i++)
        {
            total = fact[len-i-1];
            for(int j = 0; j < last; j++)
            {
                if(num[j]>0)
                {
                    now = total/((tem/fact[num[j]])*fact[num[j]-1]);
                    //printf("%lld i = %d j = %d\n", now, i, j);
                    //printf("%c", ch[j]);
                    if(now >= n)
                    {
                        res[i] = ch[j];
                        tem = ((tem/fact[num[j]])*fact[num[j]-1]);
                        num[j]--;
                        //printf("%c\n", ch[j]);
                        break;
                    }
                    else
                        n -= now;
                }
            }
        }
        res[len] = 0;
        printf("Case %d: %s\n", te, res);
    }
    return 0;
}
