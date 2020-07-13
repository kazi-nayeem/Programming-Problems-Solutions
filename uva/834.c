#include<stdio.h>


int a[100];

int st(int n, int m, int i);

int main()
{
    int n, m, i, t;
    scanf("%d %d", &n, &m);
    a[0] = n / m;
    t = st(m, n%m, 1);
    printf("[%d;", a[0]);
    for(i = 1; i < t ; ++i)
    {
        printf("%d", a[i]);
        if(i < t-1)
        printf(",");
    }
    printf("]\n");
    return 0;
}

int st(int n, int m, int i)
{
    if(n == 1)
    {
        a[i] = m;
        return i;
    }
    a[i] = n / m;
    return(st(m, n%m, i+1));
}
