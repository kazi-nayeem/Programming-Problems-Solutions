#include<stdio.h>

int main()
{
    int mem, i, j;
    char pri[16][10] = {"Happy",
                        "birthday",
                        "to",
                        "you",
                        "Happy",
                        "birthday",
                        "to",
                        "you",
                        "Happy",
                        "birthday",
                        "to",
                        "Rujia",
                        "Happy",
                        "birthday",
                        "to",
                        "you"};
    char name[101][105];
    scanf("%d", &mem);
    getchar();
    for(i = 0; i < mem; i++)
        gets(name[i]);
    if(mem < 17)
    {
        for(i = 0; i < 16; i++)
            printf("%s: %s\n", name[i%mem], pri[i]);
    }
    else
    {
        i = mem % 16;
        if(i)
            j = mem + 16 - i;
        else
            j = mem;
        for(i = 0; i < j ;i++)
            printf("%s: %s\n", name[i%mem], pri[i%16]);
    }
    return 0;
}
