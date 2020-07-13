#include<stdio.h>

int main()
{
    long int b, s, t = 1;
    while(scanf("%ld%ld", &b, &s) == 2)
    {
        if(b == 0 && s == 0) break;
        if(b == 1)
            printf("Case %d: :-\\\n", t++);
        else if(b > s)
            printf("")
    }
}
