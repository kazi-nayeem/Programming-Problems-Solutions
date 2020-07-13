#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAXC 10005

int main()
{
    int len, i, j, k;
    char input[MAXC];
    char output[MAXC];
    double s;
    int n;
    int time;
    scanf(" %d", &time);
    getchar();
    while(time--)
    {
        gets(input);
        len = strlen(input);
        s = sqrt(len);
        n = (int) s;
        if(n < s)
        {
            printf("INVALID\n");
            continue;
        }
        for(i = k = 0; i < n ; i++)
            for(j = i; j < len; j += n)
            output[k++] = input[j];
        output[len] = '\0';
        puts(output);
    }
    return 0;
}
