#include<stdio.h>

int main()
{
    char ch;
    int time, test;
    int totalm, totalpm, totalti, notply;
    int bang, www;
    int i, j;
    scanf(" %d", &time);
    for(test = 0; test < time; )
    {
        scanf(" %d", &totalm);
        getchar();
        totalpm = 0, totalti = 0, notply = 0;
        bang = 0, www = 0;
        for(i = 0; i < totalm;i++)
        {
            ch = getchar();
            if(ch == 'B')
                bang++;
            else if(ch == 'W')
                www++;
            else if(ch == 'T')
                totalti++;
            else
                notply++;
        }
        getchar();
        printf("Case %d: ", ++test);
        if(notply == totalm)
            puts("ABANDONED");
        else if(bang == totalm - notply)
            puts("BANGLAWASH");
        else if(www == totalm - notply)
            puts("WHITEWASH");
        else if(www == bang)
            printf("DRAW %d %d\n", bang, totalti);
        else if(www > bang)
            printf("WWW %d - %d\n", www, bang);
        else
            printf("BANGLADESH %d - %d\n", bang, www);
    }
    return 0;
}

