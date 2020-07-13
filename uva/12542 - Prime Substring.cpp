#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define MX 100010

int maxi;
char str[260], flag[MX];

void sieve(void);
void input(int n);
int output(int n);
void substring(int pos);
void check(int i, int j);

int main()
{
    sieve();
    while(gets(str))
    {
        int len = strlen(str);
        if(len == 1 && str[0] == '0') return 0;
        maxi = 0;
        substring(len-1);
        printf("%d\n", maxi);
    }
    return 0;
}


void sieve(void)
{
    input(0);
    input(1);
    int root = (int)sqrt(MX)+1;
    for(int i = 4; i < MX; i+=2)
        input(i);
    for(int i = 3; i <= root; i+=2)
    {
        if(output(i))
        {
            int ad = i << 1;
            for(int j = i*i; j < MX; j+=ad)
                input(j);
        }
    }
    return;
}
void input(int n)
{
    int pos, num;
    pos = n % 8;
    num = n / 8;
    flag[num] = flag[num] | (1 << pos);
    return;
}
int output(int n)
{
    int num, pos;
    num = n / 8;
    pos = n % 8;
    if((flag[num]>>pos)&1) return 0;
    return 1;
}
void substring(int pos)
{
    if(pos < 0) return;
    int i = max(0,pos-4);
    for(;i <= pos;i++)
        check(i,pos);
    substring(pos-1);
    return;
}
void check(int i, int j)
{
    int k, n = 0;
    char str2[10];
    for(k = 0; i <= j; i++, k++)
        str2[k] = str[i];
    str2[k] = '\0';
    sscanf(str2, "%d", &n);
    if(output(n))
        if(n > maxi) maxi = n;
    return;
}
