#include<stdio.h>

int main()
{
    int l, w, h;
    int t, test;
    scanf(" %d", &test);
    for(t = 0; t < test ; ++t)
    {
        scanf(" %d %d %d", &l, &w , &h);
        if(l < 21 && w < 21 && h < 21)
            printf("Case %d: good\n", t + 1);
        else
            printf("Case %d: bad\n", t + 1);
    }
    return 0;
}
