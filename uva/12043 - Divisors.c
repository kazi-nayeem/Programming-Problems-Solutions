#include<stdio.h>
#include<math.h>
#define LLI long long int
int main()
{
    long int a, b, n;
    LLI total, divis;
    register long int i, j, k;
    double root;
    int time;
    scanf("%d", &time);
    while(time--)
    {
        total = 0, divis = 0;
        scanf("%ld %ld %ld", &a, &b, &n);
        k = a % n;
        if(k == 0)
            i = a;
        else
            i = a - k + n;
        for(;i <= b; i+= n)
        {
            root = (double) sqrt(i);
            if(root == (long int) root)
                total -= root, divis --;
            total += i + 1;
            divis += 2;
            for(j = 2; j <= root; j++)
            {
                if(i % j == 0)
                {
                    total += j + (i/j);
                    divis += 2;
                }
            }
        }
        printf("%lld %lld\n", divis, total);
    }
    return 0;
}
