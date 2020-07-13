#include<stdio.h>

int main()
{
    register int i;
    int number[16];
    int n;
    scanf(" %d", &n);
    int sum;
    while(n--)
    {
        for(i = 0; i < 16; i += 4)
        {
            scanf(" %1d%1d%1d%1d", &number[i], &number[i+1], &number[i+2], &number[i+3]);
            number[i] = number[i] << 1;
            number[i+2] = number[i+2] << 1;
            if(number[i] > 9)
                number[i] -= 9;
            if(number[i+2] > 9)
                number[i+2] -= 9;
        }
        for(sum = i = 0; i < 16; i++)
            sum += number[i];
        if(sum%10)
            printf("Invalid\n");
        else
            printf("Valid\n");
    }
    return 0;
}
