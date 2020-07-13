#include<stdio.h>
#include<string.h>
int main()
{
    int a, b, c;
    char job, result[5];
    int right = 0;
    while(scanf(" %d%c%d=%s", &a, &job, &b, result) == 4)
    {
        if(result[0] != '?')
        {
            sscanf(result, "%d", &c);
            if(job == '+')
            {
                if(a+b == c)
                    right++;
            }
            else if(a - b == c)
                    right++;
        }
    }
    printf("%d\n", right);
    return 0;
}
