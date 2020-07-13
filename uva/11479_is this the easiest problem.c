#include<stdio.h>

int main()
{
    int t, tt;
    long long int x, y, z;
    scanf(" %d", &t);
    for(tt = 0; t > tt;)
    {
        scanf(" %lld %lld %lld", &x, &y, &z);
        if(x > 0 && y > 0 && z > 0){
        if( x == y && y == z)
            printf("Case %d: Equilateral\n", ++tt);
        else{
                if(x > y)
                    x ^= y ^= x ^= y;
                if(x > z)
                    x ^= z ^= x ^= z;
                if(y > z)
                    y ^= z ^= y ^= z;
                if( x + y > z)
                {
                    if((x == y) ^ (y == z))
                        printf("Case %d: Isosceles\n", ++tt);
                    else
                        printf("Case %d: Scalene\n", ++tt);

                }
                else
                    printf("Case %d: Invalid\n", ++tt);
            }
        }
        else
            printf("Case %d: Invalid\n", ++tt);
    }
    return 0;
}
