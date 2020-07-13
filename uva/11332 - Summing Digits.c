#include<stdio.h>

int main()
{
    long int n;
    int sum;
    while(scanf("%ld", &n) == 1 && n !=0)
    {
        for(sum = 0;n > 0 || sum > 9; n /= 10)
        {
            if(n == 0 && sum > 9){
                n = sum;
                sum = 0;
            }
            sum += n % 10;
        }
        printf("%d\n", sum);
    }
    return 0;
}
