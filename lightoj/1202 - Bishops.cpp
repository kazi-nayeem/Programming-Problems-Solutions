#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int r1, c1, r2, c2, ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        if(((r1+c1)&1) != ((r2+c2)&1))
            printf("Case %d: impossible\n", te);
        else if(abs(r1-r2) == abs(c2-c1))
            printf("Case %d: 1\n", te);
        else
            printf("Case %d: 2\n", te);
    }
    return 0;
}
