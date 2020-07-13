#include<stdio.h>
#define LLI long long int

int main()
{
    int a, b, c, d, l;
    int i, total;
    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &l) == 5)
    {
        if(a == 0 && b == 0 && c == 0 && d == 0 && l == 0) break;
        if(a == 0 && b == 0)
        {
            if(c %d == 0)
                printf("%d\n", l+1);
            else
                printf("0\n");
            continue;
        }
        total = 0;
        for(i = 0; i <= l; i++)
        {
            if((a*i*i+b*i+c)%d == 0 )
                total++;
        }
        printf("%d\n", total);
    }
    return 0;
}
