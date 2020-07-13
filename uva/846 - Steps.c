#include<stdio.h>
#include<math.h>

int main()
{
    long long int m, n;
    long long int first, second, diff;
    int time;
    scanf("%d", &time);
    while(time--)
    {
        scanf("%lld%lld", &m, &n);
        diff = n - m;
        if(diff == 0)
        {
            printf("0\n");
            continue;
        }
        first = (long long int) floor(sqrt(diff));
        second = first * first;
        if(second == diff)
            printf("%lld\n", first + first - 1);
        else if(second + first >= diff)
            printf("%lld\n", first + first);
        else
            printf("%lld\n", first + first + 1);
    }
    return 0;
}
