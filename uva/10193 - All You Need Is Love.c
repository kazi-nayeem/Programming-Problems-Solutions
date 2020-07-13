#include<stdio.h>
#include<string.h>

#define magnitiue(n) { \
                         len = strlen(str); \
                         for(n = i = 0; i < len; i++) \
                            if(str[i] == '1')  \
                            { \
                                n = n ^ (1 << (len - i - 1)); \
                            } \
                        }

int main()
{
    char str[70];
    int len;
    int i, j;
    unsigned long long int n, m;
    unsigned long long int gcd;
    int time, test;
    scanf("%d", &time);
    getchar();
    for(test = 0; test < time;)
    {
        gets(str);
        magnitiue(n);
        gets(str);
        magnitiue(m);
        for(gcd = m; n % gcd != 0; )
        {
            m = n % gcd;
            n = gcd;
            gcd = m;
        }
    if(gcd == 1)
        printf("Pair #%d: Love is not all you need!\n", ++test);
    else
        printf("Pair #%d: All you need is love!\n", ++test);
    }
    return 0;
}

