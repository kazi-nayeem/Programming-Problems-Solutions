#include<stdio.h>
#include<string.h>
#include<ctype.h>

int data[26];

int main()
{
    char str[1005];
    int len, i, max;
    int test;
    char ch;
    scanf("%d", &test);
    getchar();
    while(test --)
    {
        gets(str);
        len = strlen(str);
        if(len == 0) break;
        for(i = 0; i < len; i++)
        {
            ch = tolower(str[i]);
            if(ch >= 'a' && ch <= 'z')
                data[ch - 'a']++;
        }
        for(max = 0, i = 0; i < 26; i++)
            if(max < data[i])
                max = data[i];
        for(i = 0; i < 26; i++)
        {
            if(max == data[i])
                putchar(i + 97);
            data[i] = 0;
        }
        putchar('\n');
    }
    return 0;
}

