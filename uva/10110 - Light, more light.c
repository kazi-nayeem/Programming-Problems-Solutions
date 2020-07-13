#include<stdio.h>
#include<math.h>

int main()
{
    long long int n, i;
    double a;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0) break;
        if(n > 0){
            a =  sqrt(n);
            i = (unsigned long int) a;
            if( a == i)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
