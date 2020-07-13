#include<stdio.h>
#include<string.h>

#define MAX 1000000

int main()
{
    char first[MAX], second[MAX];
    int i, j, len1, len2;
    int segnal;
    while(scanf(" %s %s", first, second) == 2)
    {
        segnal = 1;
        len1 = strlen(first);
        len2 = strlen(second);
        for(i = 0, j = 0; i < len1; j++)
        {
            if(j == len2)
            {
                segnal = 0;
                break;
            }
            if(first[i] == second[j])
                i++;

        }
        if(segnal)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
