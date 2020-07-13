#include<stdio.h>
#include<string.h>

#define MAX 1005

int main()
{
    int len, i, j, k;
    int start, end;
    char string[MAX];
    while(gets(string))
    {
        len = strlen(string);
        for(i = 0; i < len; ++i)
        {
            if(string[i] != ' ')
            {
                start = i;
                while(string[i+1] != ' ' && string[i+1] != '\0')
                    i++;
                end = i;
            for(j = end; j >= start; j--)
                putchar(string[j]);
            }
            else
                putchar(string[i]);
        }
        putchar('\n');
    }
    return 0;
}
