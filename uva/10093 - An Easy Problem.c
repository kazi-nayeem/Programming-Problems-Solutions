#include<stdio.h>

int main()
{
    char ch;
    while(scanf(" %ch", &ch) == 1)
    {
        if(ch <= '9' && ch > '0')
            printf("%d\n", ch - 47);
        else if(ch >= 'A' && ch <= 'Z')
            printf("%d\n", ch - 54);
        else if(ch >= 'a' && ch <= 'z')
            printf("%d\n", ch - 60);
        else
            printf("such number is impossible!\n");
    }
    return 0;
}
