#include<stdio.h>

int main()
{
    int n, m, i, t;
    while(scanf("%d %d", &n, &m) == 2){
    printf("[%d;", n / m);
    for(t = n%m; t > 1 ; )
    {
        printf("%d,", m/t);
        i = t;
        t = m%t;
        m = i;
    }
    printf("%d]\n", m);
    }
    return 0;
}
