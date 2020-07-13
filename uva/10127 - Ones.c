#include<stdio.h>

int main()
{
    int a;
    int l;
    int k, no;
    while(scanf("%i",&a) == 1)
    {
        l=1;
        k=1,no=1;
        while(1)
        {
            l = k % a;
            if(l==0)
            {
                printf("%d\n", no);
                break;
            }
            k= l * 10 + 1;
            no++;
        }
    }
    return 0;
}
