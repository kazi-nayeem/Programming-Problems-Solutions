#include<stdio.h>

int main()
{
    int test, peo, box, cho, mtot, b, tem;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &peo, &box);
        mtot = 0;
        while(box--)
        {
            scanf("%d", &b);
            tem = 1;
            while(b--)
            {
                scanf("%d", &cho);
                tem = (tem * cho) % peo;
            }
            mtot += tem;
            mtot %= peo;
        }
        printf("%d\n", mtot);
    }
    return 0;
}
