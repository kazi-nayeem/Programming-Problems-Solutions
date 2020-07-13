#include<stdio.h>
#include<string.h>

int main()
{
    char word[10];
    int test = 1;
    while(scanf(" %[^\n]", word) == 1)
    {
        if(word[0] == '*' && word[1] == '\0') break;
        else if(strcmp(word,"Hajj") == 0)
            printf("Case %d: Hajj-e-Akbar\n", test++);
        else
            printf("Case %d: Hajj-e-Asghar\n", test++);
    }
    return 0;
}
