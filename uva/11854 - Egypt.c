#include<stdio.h>

int main()
{
    long long int x, y, z;
    while(scanf(" %lld %lld %lld", &x, &y, &z) == 3)
    {
        if( x == 0 && y == 0 && z == 0) break;
        if(x > y)
            x ^= y ^= x ^= y;
        if(x > z)
            x ^= z ^= x ^= z;
        if(y > z)
            y ^= z ^= y ^= z;
        x *= x;
        y *= y;
        z *= z;
        if(x + y == z)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}
