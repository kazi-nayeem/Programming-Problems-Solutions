#include<stdio.h>
#include<string.h>

int main()
{
    char arry[100], rarry[100];
    int group, i, j, l, m, k;
    while(scanf(" %d", &group) == 1 && group != 0)
    {
        gets(arry);
        l = strlen(arry);
        m = l / group;
        for(i = 0, l = 0; i  < group ;)
        {
            j = ((++i) * m ) - 1;
            for(k = j - m; k < j ; j--, l++ )
                rarry[l] = arry[j];
        }
        puts(rarry);
    }
    return 0;
}

