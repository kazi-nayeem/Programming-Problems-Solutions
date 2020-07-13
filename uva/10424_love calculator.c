#include<stdio.h>
#include<string.h>
#include<ctype.h>

int tosum(char arr[], unsigned int stlen);

int main()
{
    char first[100], second[100];
    unsigned int sum1, sum2, lenfirst, lensecond;
    float rati;
    while(gets(first))
    {
        if(( lenfirst = strlen(first)) == 0)
            break;
        gets(second);
        lensecond = strlen(second);
        sum1 = tosum( first , lenfirst);
        sum2 = tosum( second , lensecond);
        if(sum1 > sum2)
            rati = (float) sum2 / sum1;
        else
            rati = (float) sum1 / sum2;
        printf("%.2f %%\n", rati * 100);
    }
    return 0;
}

int tosum(char arr[], unsigned int stlen)
{
    int i, sum = 0, c;
    for(i = 0; i < stlen; ++i)
    {
        c = tolower(arr[i]) - 96;
        if( c > 0 && c < 27)
            sum += c;
    }
    i = sum;
    for( sum = 0; i > 0 || sum > 9; i /= 10)
    {
        if(i == 0 && sum > 9)
        {
            i = sum;
            sum =0;
        }
        sum += i%10;
    }
    return sum;
}

