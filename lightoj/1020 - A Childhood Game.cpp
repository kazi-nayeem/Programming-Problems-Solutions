#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

int main()
{
    char st[10];
    int te, ti, ball, tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%s", &ball, st);
        if(st[0] == 'A')
        {
            if(ball>2)
                ball = ((ball-2)/2)+(ball%2)+2;
            printf("Case %d: %s\n", te, (ball&1)? "Bob":"Alice");
        }
        else
        {
            ball = (ball/2)+(ball%2);
            printf("Case %d: %s\n", te, (ball&1)? "Bob":"Alice");
        }
    }
    return 0;
}
