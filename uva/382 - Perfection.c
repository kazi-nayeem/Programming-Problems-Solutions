#include<stdio.h>
#include<math.h>

int main()
{
    long int n, sum;
    register int count, sqn, t;
    printf("PERFECTION OUTPUT\n");
    while(scanf(" %ld", &n) == 1 && n != 0)
    {
        if(n == 1)
            printf("    1  DEFICIENT\n");
        else
        {
            sqn = sqrt(n) + 1;
            for(count = 2, sum = 1; count < sqn && sum <= n; ++count)
            {
                if(n % count == 0)
                {
                    t = n / count;
                    if(t == count)
                        sum += count;
                    else
                        sum = sum + count + t;
                }
            }
            if(sum == n)
                printf("%5ld  PERFECT\n", n);
            else if(sum < n)
                printf("%5ld  DEFICIENT\n", n);
            else
                printf("%5ld  ABUNDANT\n", n);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
