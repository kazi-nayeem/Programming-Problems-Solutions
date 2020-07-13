#include<stdio.h>
#include<string.h>

#define MAX 102

int main()
{
    int len1;
    char string[MAX], ch;
    int i, j;
    while(scanf("%c", &ch)== 1)
    {
        getchar();
        gets(string);
        len1 = strlen(string);
        if(len1 == 1)
            if(ch == '0' && string[0] == '0') break;
        for(i = j = 0; i < len1; i++)
        {
            if(string[i] != ch)
                string[j++] = string[i];
        }
        string[j--] = '\0';
        if(j == -1)
            printf("0\n");
        else
        {
            for(i = 0; string[i] == '0' && i < j; i++);
            printf("%s\n", string+i);
        }
    }
    return 0;
}
