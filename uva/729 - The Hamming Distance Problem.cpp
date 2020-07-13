#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

char str[20];
int n;

void backtrack(int pos, int h);

int main()
{
    int ti, h;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &h);
        backtrack(0,h);
        if(ti)  putchar('\n');
    }
    return 0;
}

void backtrack(int pos, int h)
{
    if(pos == n)
    {
        if(h == 0)
        {
            str[pos] = '\0';
            puts(str);
        }
        return;
    }
    if(h < 0) return;

    str[pos] = '0';
    backtrack(pos+1,h);
    str[pos] = '1';
    backtrack(pos+1,h-1);
    return;
}
