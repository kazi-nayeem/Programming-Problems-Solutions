#include<cstdio>
#include<cstring>
using namespace std;

int queen[8];
int arr[8], mini;

void solve(int pos, int mov);
bool is_safe(int col, int row);

int main()
{
    int te = 1;
    while(scanf("%d", &queen[0]) == 1)
    {
        for(int i = 1; i < 8; i++)
            scanf("%d", &queen[i]);
        memset(arr,0, sizeof arr);
        mini = 9;
        solve(0,0);
        printf("Case %d: %d\n",te++, mini);
    }
    return 0;
}

void solve(int pos, int mov)
{
    if(pos >= 8)
    {
        if(mov < mini) mini = mov;
        return;
    }
    if(mov >= mini) return;
    for(int i = 1; i <= 8; i++)
    {
        if(is_safe(pos,i))
        {
            arr[pos] = i;
            if(i == queen[pos])
                solve(pos+1,mov);
            else
                solve(pos+1,mov+1);
        }
    }
    return;
}
bool is_safe(int col, int row)
{
    for(int i = 0; i < col; i++)
    {
        if(arr[i] == row || arr[i] == row-col+i || arr[i] == row+col-i)
            return false;
    }
    return true;
}
