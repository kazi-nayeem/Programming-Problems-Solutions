#include<stdio.h>
#include<string.h>

int main()
{
    char number[1005];
    int positive, negative;
    int count, len;
    while(gets(number))
    {
        len = strlen(number);
        if(len == 1 && number[0] == '0') break;
        for(count = 0, positive = 0; count < len ; count += 2)
            positive += (int) number[count] - 48;
        for(count = 1, negative = 0; count < len ; count += 2)
            negative += (int) number[count] - 48;
        if((positive - negative) % 11 == 0)
            printf("%s is a multiple of 11.\n", number);
        else
            printf("%s is not a multiple of 11.\n", number);
    }
    return 0;
}
