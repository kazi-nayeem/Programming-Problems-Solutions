#include<stdio.h>
#include<string.h>

int data[123];

int main()
{
    char str[1005];
    int len, i, max;
    while(gets(str))
    {
        len = strlen(str);
        if(len == 0) break;
        for(i = 0; i < len; i++)
            if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            data[str[i]]++;
        for(max = 0, i = 65; i < 91; i++)
            if(max < data[i])
                max = data[i];
        for(i = 97; i < 123; i++)
            if(max < data[i])
                max = data[i];
        for(i = 65; i < 91; i++)
        {
            if(max == data[i])
                putchar(i);
            data[i] = 0;
        }
        for(i = 97; i < 123; i++)
        {
            if(max == data[i])
                putchar(i);
            data[i] = 0;
        }
        printf(" %d\n", max);
    }
    return 0;
}
