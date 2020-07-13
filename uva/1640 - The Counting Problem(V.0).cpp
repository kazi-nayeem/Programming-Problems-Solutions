#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

struct data{
    int arr[10], solution, ts;
};

data dp[10][2][2];
char str[15];
int te, len;

data rec(int pos, int flag, int zero)
{
    data tem;
    if(pos == len)
    {
        for(int i = 0; i <= 9; i++)
            tem.arr[i] = 0;
        tem.solution = 1;
        return tem;
    }
    data & res = dp[pos][flag][zero];
    if(te == res.ts) return res;
    for(int i = 0; i <= 9; i++)
        res.arr[i] = 0;
    res.solution = 0;
    res.ts = te;
    int lm = (flag)? (str[pos]-'0'):9;
    for(int i = 0; i <= lm; i++)
    {
        tem = rec(pos+1,flag && (i == str[pos]-'0'), i != 0 || zero == 1);
        for(int j = 0; j <= 9; j++)
            res.arr[j] += tem.arr[j];
        res.solution += tem.solution;
        if(i == 0 && zero == 0) continue;
        res.arr[i] += tem.solution;
    }
    return res;
}

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) == 2)
    {
        if(a == 0 && b == 0) return 0;
        if(a>b)
            a ^= b ^= a ^= b;
        sprintf(str,"%d", b);
        len = strlen(str);
        te++;
        data res1 = rec(0,1,0);
        sprintf(str,"%d", a-1);
        len = strlen(str);
        te++;
        data res2 = rec(0,1,0);
        printf("%d", res1.arr[0]-res2.arr[0]);
        for(int i = 1; i <= 9; i++)
            printf(" %d", res1.arr[i]-res2.arr[i]);
        putchar('\n');
    }
    return 0;
}
