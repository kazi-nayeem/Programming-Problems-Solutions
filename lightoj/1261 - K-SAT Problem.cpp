#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char arr[31][31];
char num[31];

int main()
{
    int n, m, k, p, te, ti, tem;
    bool in, out;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        memset(arr, 0, sizeof arr);
        memset(num,0, sizeof num);
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
        {
            scanf("%d", &tem);
            if(tem > 0)
            {
                if(arr[i][tem] != '-' && arr[i][tem] != 'b')
                    arr[i][tem] = '+';
                else arr[i][tem] = 'b';
            }
            else
            {
                if(arr[i][abs(tem)] != '+' && arr[i][abs(tem)] != 'b')
                    arr[i][abs(tem)] = '-';
                else arr[i][abs(tem)] = 'b';
            }
        }
        scanf("%d", &p);
        for(int i = 0; i < p; i++)
        {
            scanf("%d", &tem);
            num[tem] = 't';
        }
        //printf("ok");
        out = false;
        for(int i = 0; i < n; i++)
        {
            in = true;
            for(int j = 1; j < 31; j++)
            {
                if(arr[i][j] == 'b')
                {
                    in = false;
                    break;
                }
                if(arr[i][j] == '+' && num[j] == 't')
                {
                    in = false;
                    break;
                }
                if(arr[i][j] == '-' && num[j] != 't')
                {
                    in = false;
                    break;
                }
            }
            out = in;
            if(out) break;
        }
        if(out) printf("Case %d: No\n", te);
        else printf("Case %d: Yes\n", te);
    }
    return 0;
}
