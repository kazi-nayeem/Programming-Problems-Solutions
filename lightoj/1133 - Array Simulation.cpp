#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int arr[100];

int main()
{
    freopen("input.txt", "r", stdin);
    char str[15];
    int te, ti, n, x, y, q, tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf(" %d", arr+i);
        gets(str);
        for(int k = 0; k < q; k++)
        {
            gets(str);
            if(str[0] == 'S')
            {
                sscanf(str+2, "%d", &x);
                for(int i = 0; i < n; i++)
                    arr[i]+=x;
            }
            else if(str[0] == 'M')
            {
                sscanf(str+2, "%d", &x);
                for(int i = 0; i < n; i++)
                    arr[i]*=x;
            }
            else if(str[0] == 'D')
            {
                sscanf(str+2, "%d", &x);
                for(int i = 0; i < n; i++)
                    arr[i]/=x;
            }
            else if(str[0] == 'R')
            {
                for(int i = 0, j = n -1; i < j; i++, j--)
                {
                    x = arr[i];
                    arr[i] = arr[j];
                    arr[j] = x;
                }
            }
            else if(str[0] == 'P')
            {
                sscanf(str+2, "%d %d ", &x, &y);
                tem = arr[x];
                arr[x] = arr[y];
                arr[y] = tem;
            }
        }
        printf("Case %d:\n%d", te, arr[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", arr[i]);
        puts("");
    }
    return 0;
}
