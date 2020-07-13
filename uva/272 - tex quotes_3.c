#include<stdio.h>
#include<string.h>

int main()
{
    char tex[1000];
    int len, count, flag;
    while(scanf(" %[^\n]", tex) == 1)
    {
        len = strlen(tex);
        for(flag = 0, count = 0; count < len; ++count)
        {
            if(tex[count] == '"' && flag == 0)
            {
                flag = 1;
                printf("``");
            }
            else if(tex[count] == '"' && flag == 1)
            {
                    flag = 0;
                    printf("''");
            }
            else
                printf("%c", tex[count]);
        }
        printf("\n");
    }
    return 0;
}

