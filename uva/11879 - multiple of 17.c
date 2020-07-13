#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 105

int main()
{
    char string[MAX];
    int count, len, m;
    long long int number, extra;
    while(gets(string))
    {
        len = strlen(string);
        if(len == 1 && string[0] == '0') break;
        for(count = extra = 0; count < len; count += 15)
        {
            sscanf(string + count, "%15lld", &number);
            number += extra;
            extra = number % 17;
            if(extra != 0)
            {
                m = len - count - 15;
                if(m == 0);
                else if(m >= 15)
                {
                    extra *= 10000000;
                    extra *= 100000000;
                }
                else if(m > 0)
                    extra *= (long long int) pow(10,m);
            }
        }
        if(extra == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
