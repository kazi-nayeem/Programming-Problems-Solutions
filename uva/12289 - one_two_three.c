#include<stdio.h>
#include<string.h>

int main()
{
    char word[7];
    int t, l;
    scanf("%d ", &t);
    for(;t > 0; --t)
    {
        gets(word);
        l = strlen(word);
        if(l == 5)
            printf("3\n");
        else if((word[0] == 'o' && word[1] == 'n') ||
                (word[1] == 'n' && word[2] == 'e') ||
                (word[0] == 'o' && word[2] == 'e'))
                    printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
