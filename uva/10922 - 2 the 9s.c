#include<stdio.h>
#include<string.h>

#define MAX 1005
int main()
{
    char number[MAX];
    int total, sum;
    int len;
    int count;
    int degree;
    while(gets(number))
    {
        len = strlen(number);
        if(len == 1)
            {
                if(number[0] == '0')
                    break;
                else if(number[0] == '9')
                    printf("9 is a multiple of 9 and has 9-degree 1.\n");
                else
                    printf("%s is not a multiple of 9.\n", number);
            }
        else
        {
            for(count = total = 0; count<len ; ++count)
            {
                total += ((int) number[count] - 48);
            }
            for(degree = 2, sum = 0; total > 0 || sum > 9 ; total /= 10)
            {
                if(total == 0 && sum > 9)
                {
                    degree++;
                    total = sum;
                    sum = 0;
                }
                sum += (total % 10);
            }
        if(sum == 9)
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, degree);
        else
            printf("%s is not a multiple of 9.\n", number);
        }
    }
    return 0;
}
