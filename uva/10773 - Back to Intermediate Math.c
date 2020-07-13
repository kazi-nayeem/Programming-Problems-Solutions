#include<stdio.h>
#include<math.h>

int main()
{
    int nt, t;
    float d, v, u, t1, t2, k;
    scanf("%d", &nt);
    for( t = 0 ; t < nt ; )
    {
        scanf("%f %f %f", &d, &v, &u);
        if(v >= u || v == 0)
            printf("Case %d: can't determine\n", ++t);
        else
        {
            t1 = d / u;
            k = sqrt( u * u - v * v);
            t2 = d / k;
            printf("Case %d: %.3f\n", ++t, t2 - t1);
        }
    }
    return 0;
}


