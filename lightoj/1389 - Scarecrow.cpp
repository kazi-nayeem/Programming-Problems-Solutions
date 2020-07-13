#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    char str[105];
    int te, ti, len;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &len);
        getchar();
        gets(str);
        int total = 0;
        for(int i = 0; i < len; i++)
            if(str[i] == '.') total++, i += 2;

        printf("Case %d: %d\n", te, total);
    }
    return 0;
}

