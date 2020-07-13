#include<stdio.h>
#include<string.h>

int main()
{
    char tex[1000], fin_tex[1100];
    int len, count, fcount, flag;
    while(gets(tex))
    {
        len = strlen(tex);
        if(len == 0) break;
        for(flag = 0, count = 0, fcount = 0; count < len ; ++count, fcount++)
        {
            if(tex[count] == '"')
            {
                if(flag)
                {
                    flag = 0;
                    fin_tex[fcount++] = '\'';
                    fin_tex[fcount] = '\'';
                }
                else
                {
                    flag = 1;
                    if(count < len - 2)
                    {
                        fin_tex[fcount++] = '`';
                        fin_tex[fcount] = '`';
                    }
                    else
                    {
                        fin_tex[fcount++] = '\'';
                        fin_tex[fcount] = '\'';
                    }
                }
            }
            else
                fin_tex[fcount] = tex[count];
        }
        fin_tex[fcount] = '\0';
        printf("%s\n", fin_tex);
    }
    return 0;
}
