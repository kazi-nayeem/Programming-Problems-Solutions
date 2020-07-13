#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int time, test, total, st, dust;
    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d", &st);
        total = 0;
        for(int i = 0; i < st; i++)
        {
            scanf("%d", &dust);
            if(dust>0)
                total += dust;
        }
        printf("Case %d: %d\n", test, total);
    }
    return 0;
}
