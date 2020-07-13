#include<stdio.h>
#define MX 50005

long long int len[MX];

int main()
{
    long long int i, j, k;
    long long int mid;
    long long int num;
    long long int test;
    long long int chimp;
    scanf("%lld", &num);
    for(i = 0; i < num; i++)
        scanf("%lld", &len[i]);
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld", &chimp);
        mid = num >> 1;
        for(i = 0, j = num - 1; i < j;mid = (i+j)>>1)
        {
            if(len[mid] == chimp)
                break;
            else if(len[mid] > chimp)
                j = mid - 1;
            else
                i = mid + 1;
        }
        if(len[mid] == chimp)
        {
            if(mid > 0)
                printf("%lld", len[mid-1]);
            else
                putchar('X');
            if(mid + 1 < num)
                printf(" %lld\n", len[mid+1]);
            else
                puts(" X");
        }
        else if(mid <= 0)
        {
            if(len[0] < chimp)
                printf("%lld X\n", len[0]);
            else
                printf("X %lld\n", len[0]);
        }
        else if(mid + 1 >= num && len[mid] < chimp)
            printf("%lld X\n", len[mid]);
        else
        {
            if(len[mid] > chimp)
            {
                if(mid > 0)
                    printf("%lld", len[mid-1]);
                else
                    putchar('x');
                printf(" %lld\n", len[mid]);
            }
            else if(len[mid] < chimp && len[mid+1]>chimp)
                printf("%lld %lld\n", len[mid], len[mid+1]);
            else
                printf("%lld %lld\n", len[mid+1],len[mid]);
        }
    }
    return 0;
}
