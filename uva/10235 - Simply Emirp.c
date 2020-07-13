#include<stdio.h>
#include<math.h>
#include<string.h>

#define MX 1000010

int flag[MX];

void sieve(void);
int chack(int n);

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(flag[n] == 1)
            printf("%d is not prime.\n", n);
        else if( chack(n))
            printf("%d is emirp.\n", n);
        else
            printf("%d is prime.\n", n);
    }
    return 0;
}

int chack(int n)
{
    int m = n;
    char str1[10], str2[10];
    sprintf(str1, "%d", n);
    int len = strlen(str1);
    int j = len - 1, i;
    for(i = 0; i < len; i++, j--)
        str2[i] = str1[j];
    str2[len] = '\0';
    sscanf(str2,"%d",&n);
    if(flag[n] == 1 || m == n) return 0;
    return 1;
}

void sieve(void)
{
    int i, j, ad;
    flag[1] = flag[0] = 1;
    for(i = 4; i < MX; i+=2) flag[i] = 1;
    for(i = 3; i <= 1010; i+=2)
    {
        if(flag[i] == 0)
        {
            ad = i << 1;
            for(j = i * i; j < MX; j += ad)
                flag[j] = 1;
        }
    }
    return;
}
