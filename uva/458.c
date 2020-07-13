#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char str[100];
    int l, i;
    while(gets(str))
    {
        l = strlen(str);
        for( i = 0; i < l ; ++i)
            str[i] -= 7;
        puts(str);
    }
    return 0;
}
