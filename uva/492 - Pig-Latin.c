#include<stdio.h>
#include<string.h>

#define MAXI 1000005
#define MAXO 1000005

int main()
{
    int i, j, k, len;
    int start, end;
    char input[MAXI], output[MAXO];
    char ch, temp;
    int flag;
    while(gets(input))
    {
        len = strlen(input);
        for(j = i = 0; i < len; i++)
        {
            ch = tolower(input[i]);
            if(ch <= 'z' && ch >= 'a')
            {
                start = i;
                ch = tolower(input[++i]);
                while(ch >= 'a' && ch <= 'z')
                    ch = tolower(input[++i]);
                end = --i;
                ch = tolower(input[start]);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    flag = 0;
                else
                {
                    temp = input[start++];
                    flag = 1;
                }
                for(;start <= end;++start)
                    output[j++] = input[start];
                if(flag)
                    output[j++] = temp;
                output[j++] = 'a';
                output[j++] = 'y';


            }
            else
                output[j++] = input[i];
        }
        output[j] = '\0';
        puts(output);
    }
    return 0;
}
