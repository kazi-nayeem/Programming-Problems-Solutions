#include<cstdio>
#include<cstring>
using namespace std;

char str[100005];
char cop[100005];

int main()
{
    int te, ti, len, di;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %s", str);
        printf("Case %d: ", te);
        len = strlen(str);
        cop[len] = 0;
        di = (len+1)/2;
        for(int i = 0; i < di; i++)
        {
            cop[i] = cop[len-i-1] = str[i];
        }
        int flag = -1;
        for(int i = di; i < len; i++)
        {
            if(str[i] < cop[i])
            {
                flag = 1;
                break;
            }
            if(str[i] > cop[i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            puts(cop);
            continue;
        }
        for(int i = di-1; i >= 0; i--)
        {
            if(cop[i] == '9')
            {
                cop[i] = cop[len-i-1] = '0';
            }
            else
            {
                cop[i]++;
                cop[len-i-1] = cop[i];
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            puts(cop);
            continue;
        }
        printf("1");
        for(int i = 1; i < len; i++)
            printf("0");
        printf("1\n");
    }
    return 0;
}
