#include<stdio.h>

int main()
{
    int n, countt, one, flag, c;
    while(scanf(" %d", &n) == 1)
    {
        if(n == 0) break;
        printf("The parity of ");
        for(countt = 31; countt > -1; --countt)
            if(( n >> countt ) & 1)
                break;
        for(one = 0 , flag = 0; countt > -1 ; --countt)
        {
            if(c = ( n >> countt ) & 1) one++;
            printf("%d", c);
        }
        printf(" is %d (mod 2).\n", one);
    }
    return 0;
}
