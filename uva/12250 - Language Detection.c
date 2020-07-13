#include<stdio.h>
#include<string.h>

int main()
{
    char language[20];
    int test = 1;
    while(gets(language))
    {
        if(strcmp(language,"HELLO") == 0)
            printf("Case %d: ENGLISH\n", test++);
        else if(strcmp(language,"HOLA") == 0)
            printf("Case %d: SPANISH\n", test++);
        else if(strcmp(language,"HALLO") == 0)
            printf("Case %d: GERMAN\n", test++);
        else if(strcmp(language,"BONJOUR") == 0)
            printf("Case %d: FRENCH\n", test++);
        else if(strcmp(language,"CIAO") == 0)
            printf("Case %d: ITALIAN\n", test++);
        else if(strcmp(language,"ZDRAVSTVUJTE") == 0)
            printf("Case %d: RUSSIAN\n", test++);
        else if(strcmp(language,"#") == 0)
            break;
        else
            printf("Case %d: UNKNOWN\n", test++);
    }
    return 0;
}
