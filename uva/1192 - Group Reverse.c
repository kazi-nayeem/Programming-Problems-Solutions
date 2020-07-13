#include<stdio.h>
#include<string.h>

int main()
{
    char arry[100];
    int group, i, j, l, m, k;
    while(scanf(" %d", &group) == 1 && group != 0)
    {
        getchar();
        gets(arry);
        l = strlen(arry);
        m = l / group;
        for(i = 0; i  < group ;)
        {
            j = ((++i) * m) -1;
            for(k = j - m; k < j ; )
                putchar(arry[j--]);
        }
        printf("\n");
    }
    return 0;
}

