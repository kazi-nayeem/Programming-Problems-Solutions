#include<cstdio>
using namespace std;

int main()
{
    char str[10];
    int time, test, op, total, j;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d", &op);
        printf("Case %d:\n", test);
        total = 0;
        while(op--)
        {
            getchar();
            scanf(" %s", str);
            if(str[0] == 'd')
            {
                scanf("%d", &j);
                total += j;
            }
            else
            {
                printf("%d\n", total);
            }
        }
    }
    return 0;
}
