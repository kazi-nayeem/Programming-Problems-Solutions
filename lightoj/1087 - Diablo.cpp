#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector <int > vc;

int main()
{
    int te, ti, n, q, tem;
    char ch;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        vc.clear();
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            vc.push_back(tem);
        }
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            getchar();
            ch = getchar();
            scanf("%d", &tem);
            if(ch == 'c')
            {
                if(vc.size() >= tem)
                {
                    printf("%d\n", vc[tem-1]);
                    vc.erase(vc.begin()+tem-1);
                }
                else
                    printf("none\n");
            }
            else if(ch == 'a')
                vc.push_back(tem);
        }
    }
    return 0;
}
