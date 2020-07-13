#include<stdio.h>
#include<ctype.h>

#define MAX 26

#define transfer { \
                    temp = character[i]; \
                    character[i] = character[j]; \
                    character[j] = temp; \
                }

typedef struct
{
    char c;
    int num;
} str;


str character[MAX], temp;

int main()
{
    int test;
    register i, j;
    char ch;
    for(test = 0; test < MAX; test++)
    {
        character[test].c = test + 'A';
    }
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        ch = getchar();
        while(ch != '\n')
        {
            ch = toupper(ch);
            if(ch >= 'A' && ch <= 'Z')
                character[ch - 'A'].num++;
            ch = getchar();
        }
    }
    for(i = 0; i < MAX; i++)
        for(j = i + 1; j < MAX ; j++)
        {
            if(character[i].num < character[j].num)
                transfer
            else if(character[i].num == character[j].num && character[i].c > character[j].c)
                transfer
        }
    for(i = 0; i < MAX && character[i].num != 0; i++)
        printf("%c %d\n", character[i].c, character[i].num);
    return 0;
}
