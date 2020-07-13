#include<stdio.h>
#define LI long int
#define LLI long long int
#define MX 50005
LI binary(LI n, LLI fin);
LLI hight[MX];

int main()
{
    LI n;
    LI i, j;
    LLI chimp;
    LI test;
    LI middle;
    scanf("%ld", &n);
    for(i = 0; i < n; i++)
        scanf("%lld", &hight[i]);
    scanf("%ld", &test);
    while(test--)
    {
        printf("ok\n");
        scanf("lld", &chimp);
        if(chimp > hight[0] && chimp < hight[n-1])
        {
            middle = binary( n, chimp);
            if(hight[middle] == chimp)
                printf("%lld %lld\n", hight[middle-1], hight[middle+1]);
            else
                printf("%lld %lld\n", hight[middle], hight[middle+1]);
        }
        else if(chimp < hight[0])
            printf("X %lld\n", hight[0]);
        else if(chimp == hight[0])
        {
            if(n == 1)
                printf("X X\n");
            else
                printf("X %lld\n", hight[1]);
        }
        else if(chimp == hight[n-1])
            printf("%lld X\n", hight[n-1]);
        else
            printf("%lld X\n", hight[n-2]);
    }
}

LI binary(LI n, LLI fin)
{
    return 0;
}
