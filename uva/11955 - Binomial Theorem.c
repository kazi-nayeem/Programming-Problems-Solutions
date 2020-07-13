#include<stdio.h>
#include<string.h>

int combi[40];

int main()
{
    int time, test = 1;
    int n, total, p;
    int i, j, k;
    int len;
    char str[2][105];
    char input[210];
    combi[0] = 1;
    scanf("%d", &time);
    getchar();
    while(time--)
    {
        gets(input);
        len = strlen(input);
        for(i = 1, j = 0, k = 0; i < len; i++)
        {
            if(input[i] >= 'a' && input[i] <= 'z')
                str[k][j++] = input[i];
            else if(k == 0)
            {
                i++;
                str[0][j] = '\0';
                k = 1;
                j = 0;
            }
            else
                break;
        }
        str[2][j] = '\0';
        i += 2;
        printf("%d   ==  ", i);
        sscanf(input + i, "%d", &n);
        printf("%s %s %d\n", str[0], str[1], n);
        p = n >> 1;
        for(total = 1, i = 1, j = n; i <= p; i++, j--)
        {
            total = total * j / i;
            combi[i] = total;
        }
        for(i = 0; i <= p; i++)
            printf(" %d", combi[i]);
        putchar('\n');
    }
    return 0;
}
