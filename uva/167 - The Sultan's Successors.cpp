#include<cstdio>
#include<cstring>
using namespace std;

int arr[8][8];
int sultan[8], maxi;

void successor(int pos, int sum);
bool is_safe(int row, int colum);

int main()
{
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            scanf("%d", &arr[i][j]);
        maxi = 0;
        successor(0,0);
        printf("%5d\n", maxi);
    }
    return 0;
}


void successor(int pos, int sum)
{
    if(pos >= 8)
    {
        if(maxi < sum) maxi = sum;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(is_safe(pos,i))
        {
            sultan[pos] = i;
            successor(pos+1,sum+arr[pos][i]);
        }
    }
    return;
}
bool is_safe(int row, int colum)
{
    for(int i = 0; i < row; i++)
    {
        if(sultan[i] == colum || sultan[i] == colum+row-i || sultan[i] == colum-row+i)
            return false;
    }
    return true;
}
