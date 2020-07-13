#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

struct data{
    int arr[10], solution, ts;
};

data dp[10][2][2][2];
char str1[15], str2[15];
int te, len;

data rec(int pos, int flag1, int flag2, int zero)
{
    data tem;
    if(pos == len)
    {
        for(int i = 0; i <= 9; i++)
            tem.arr[i] = 0;
        tem.solution = 1;
        return tem;
    }
    data & res = dp[pos][flag1][flag2][zero];
    if(te == res.ts) return res;
    for(int i = 0; i <= 9; i++)
        res.arr[i] = 0;
    res.solution = 0;
    res.ts = te;
    int lm = (flag1)? (str1[pos]-'0'):9;
    int lw = (flag2)? (str2[pos]-'0'):0;
    for(int i = lw; i <= lm; i++)
    {
        tem = rec(pos+1,flag1 && (i == str1[pos]-'0'),flag2 && (i == str2[pos]-'0'), i != 0 || zero == 1);
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
        sprintf(str1,"%d", b);
        len = strlen(str1);
        te++;
        for(int i = len-1; i >= 0; i--)
        {
            str2[i] = (a%10)+'0';
            a/=10;
        }
        data res1 = rec(0,1,1,0);
        printf("%d", res1.arr[0]);
        for(int i = 1; i <= 9; i++)
            printf(" %d", res1.arr[i]);
        putchar('\n');
    }
    return 0;
}
