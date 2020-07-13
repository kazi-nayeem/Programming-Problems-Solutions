#include<stdio.h>

typedef struct st{
        char name[20];
        int dd,mm,yy;
} information;

int compare(information first, information second);
int main()
{
    information youn, old, temp;
    int n, i, f;
    scanf("%d", &n);
    scanf(" %s %d %d %d", youn.name, &youn.dd, &youn.mm, &youn.yy);
    old = youn;
    for(i = 1; i < n; i++)
    {
        scanf(" %s %d %d %d", temp.name, &temp.dd, &temp.mm, &temp.yy);
        if(compare(temp,youn))
            youn = temp;
        else if(compare(old,temp))
            old = temp;
    }
    printf("%s\n%s\n", youn.name, old.name);
    return 0;
}

int compare(information first, information second)
{
    if(first.yy == second.yy)
    {
        if(first.mm == second.mm)
        {
            if(first.dd > second.dd)
                return 1;
            return 0;
        }
        if(first.mm > second.mm)
            return 1;
        return 0;
    }
    if(first.yy > second.yy)
        return 1;
    return 0;
}
