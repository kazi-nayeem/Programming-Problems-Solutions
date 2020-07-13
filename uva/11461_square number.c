#include<stdio.h>
#include<math.h>

int main()
{
    unsigned int tcount, squarenum;
    unsigned long int a, b, c, d;
    for(tcount = 0; tcount < 201; ++tcount)
    {
        scanf(" %ld %ld", &a, &b);
        if(a == 0 && b == 0) break;
        c = sqrt(a);
        if(a == (c * c))
            d = c;
        else
            d = c + 1;
        for(c = a, squarenum = 0; c <= b; ++d)
    }
}
