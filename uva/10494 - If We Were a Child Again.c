#include<stdio.h>
#include<string.h>

#define MX 1000010
#define LLI long long int
int main()
{
    char result[MX];
    char oparation;
    LLI divis;
    LLI mod, total;
    register int len, i, j;
    while(scanf(" %s %c %ld", result, &oparation, &divis) == 3)
    {
        len = strlen(result);
        for(i = 0, mod = 0; i < len; i++)
        {
            mod = (mod * 10) + (result[i] - '0');
            result[i] = (mod / divis) + '0';
            mod %= divis;
        }
        result[i] = '\0';
        if(oparation == '%')
            printf("%lld\n", mod);
        else
        {
            for(i = 0; i < len; i++)
                if(result[i] != '0')
                    break;
            if(i == len)
                puts("0");
            else
                puts(result+i);
        }
    }
    return 0;
}
