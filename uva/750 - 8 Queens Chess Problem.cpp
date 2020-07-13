#include<cstdio>
#include<cstring>
using namespace std;

int queen[8];
int te;
void solve(int pos);
bool is_safe(int row, int colum);

int main()
{
    int ti, a, b;
    scanf("%d", &ti);
    while(ti --)
    {
        memset(queen, 0, sizeof queen);
        scanf("%d %d", &a, &b);
        queen[b-1] = a;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        te = 1;
        solve(0);
        if(ti) putchar('\n');
    }
    return 0;
}

void solve(int pos)
{
    if(pos >= 8)
    {
        printf("%2d%7d", te++, queen[0]);
        for(int i = 1; i < 8; i++)
            printf(" %d", queen[i]);
        printf("\n");
        return;
    }
    if(queen[pos] != 0)
    {
        solve(pos+1);
        return;
    }
    for(int i = 1; i <= 8; i++)
    {
        if(is_safe(pos,i))
        {
            queen[pos] = i;
            solve(pos+1);
            queen[pos] = 0;
        }
    }
    return;
}
bool is_safe(int row, int colum)
{
    for(int i = 0; i < row; i++)
    {
        if(queen[i] == colum || queen[i] == colum+row-i || queen[i] == colum-row+i )
            return false;
    }
    for(int i = row+1; i < 8; i++)
    {
        if((queen[i] != 0)&&(queen[i] == colum || queen[i] == colum-i+row || queen[i] == colum+i-row))
            return false;
    }
    return true;
}
