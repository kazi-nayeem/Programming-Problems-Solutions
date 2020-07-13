#include<cstdio>
using namespace std;

int main()
{
    int te, n, mini, maxi, tem;
    scanf("%d", &te);

    while(te--)
    {
        scanf("%d", &n);
        scanf("%d", &tem);
        maxi = mini = tem;
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &tem);
            if(tem < mini)
                mini = tem;
            else if(tem > maxi)
                maxi = tem;
        }
        printf("%d\n", maxi - mini);
    }
    return 0;
}
