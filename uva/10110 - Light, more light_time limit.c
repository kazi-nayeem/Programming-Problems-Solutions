#include<stdio.h>

int main()
{
    unsigned long int n, i;
    int flag;
    while(scanf("%lu", &n) == 1)
    {
        if(n == 0) break;
        for(flag = 0, i = 1; i <= n ; ++i)
            if(!(n%i))
                flag++;
        if(flag & 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
