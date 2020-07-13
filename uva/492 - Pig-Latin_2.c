#include<stdio.h>
#include<ctype.h>

int main()
{
    int flag = 0, flagc = 0, flagay = 0;
    char ch, temp, chl;
    while((ch = getchar()) != '\n')
    {
        chl = tolower(ch);
        if(chl <= 'z' && chl >= 'a')
        {
            flagay = 1;
            if(flag)
                putchar(ch);
            else
            {
                flag = 1;
                if(chl == 'a' || chl == 'e' || chl == 'i' || chl == 'o' || chl == 'u')
                    putchar(ch);
                else
                {
                    temp = ch;
                    flagc = 1;
                }
            }
        }
        else
        {
            if(flagc)
            {
                putchar(temp);
                flagc = 0;
            }
            if(flagay)
            {
                flagay = flag = 0;
                printf("ay");
            }
            putchar(ch);
        }
    }
    if(flagay)
        printf("ay");
    putchar('\n');
    return 0;
}
