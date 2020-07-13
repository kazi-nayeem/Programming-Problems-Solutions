#include<stdio.h>
#include<string.h>

int main()
{
    int n, count;
    int len, max_pizza;
    char pizza[605];
    int a, g, i, m, r, t;
    scanf("%d ", &n);
    while(n--)
    {
        gets(pizza);
        len = strlen(pizza);
        for(count = a = g = i = m = r = t = 0; count < len ; ++count)
        {
            if(pizza[count] == 'A') a++;
            else if(pizza[count] == 'G') g++;
            else if(pizza[count] == 'I') i++;
            else if(pizza[count] == 'M') m++;
            else if(pizza[count] == 'R') r++;
            else if(pizza[count] == 'T') t++;
        }
        max_pizza = a / 3;
        if(max_pizza > g)
            max_pizza = g;
        if(max_pizza > i)
            max_pizza = i;
        if(max_pizza > m)
            max_pizza = m;
        if(max_pizza > t)
            max_pizza = t;
        if(max_pizza > (r >> 1))
            max_pizza = r >> 1;
        printf("%d\n", max_pizza);
    }
    return 0;
}
