#include<cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(2*n <= m)
        printf("%d\n", n);
    else if(2*m <= n)
        printf("%d\n", m);
    else
        printf("%d\n", (n+m)/3);
    return 0;
}
