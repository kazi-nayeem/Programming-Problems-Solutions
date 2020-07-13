#include<cstdio>
using namespace std;

int main()
{
    int tim, tes, x1, y1, x2, y2, x, y, m;
    scanf("%d", &tim);

    for(tes = 1; tes <= tim; tes++)
    {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &m);

        printf("Case %d:\n", tes);

        for(int i = 0; i < m; i++)
        {
            scanf(" %d %d", &x, &y);

            if( x >= x1 && x <= x2 && y >= y1 && y <= y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
