#include<stdio.h>
#include<string.h>

#define MAX 1005

int main()
{
    char bear[MAX];
    char palindrome[MAX];
    char sentence[MAX];
    int len;
    int i, j;
    while(gets(bear))
    {
        if(strcmp(bear, "DONE") == 0) break;
        len = strlen(bear);
        for(i = 0, j = 0; i < len; ++i)
        {
            bear[i] = tolower(bear[i]);
            if(bear[i] >= 'a' && bear[i] <= 'z')
                sentence[j++] = bear[i];
        }
        sentence[j] = '\0';
        len = j;
        palindrome[j] = '\0';
        for(i = 0, j--; i < len ; ++i, --j)
            palindrome[j] = sentence[i];
        if(strcmp(sentence, palindrome) == 0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
