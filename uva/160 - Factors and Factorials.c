#include<stdio.h>

int primenumber[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int n, i;
    int count, flag, primeflag;
    int prime[25];
    while(scanf("%d", &n) == 1 && (n != 0))
    {
        primeflag = 0;
        for(i = 0; i < 25; ++i)
           prime[i] = 0;
        for(count = 2; count <= n ; ++count)
        {
            for(i = count, flag = 0; i > 1 ; flag++)
            while((i % primenumber[flag]) == 0)
            {
                 prime[flag]++;
                 i /= primenumber[flag];
                 if(primeflag < flag)
                    primeflag = flag;
            }
        }
        printf("%3d! =", n);
        if(primeflag > 14)
        {
            for(i = 0; i < 15 ; ++i)
            printf("%3d", prime[i]);
        printf("\n      ");
        }
        else
         i = 0;
        for(; i <= primeflag ; ++i)
            printf("%3d", prime[i]);
        printf("\n");
    }
    return 0;
}
