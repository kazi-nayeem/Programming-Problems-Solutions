#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MX 12

int arr[75];
int len;
char pr[MX];
void backtrack(int dept);

int main()
{
    char str[MX], ti;
    scanf("%d", &ti);
    gets(str);
    while(ti--)
    {
        gets(str);
        len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            arr[str[i]-'0']++;
        }
        backtrack(0);
        memset(pr, 0, sizeof pr);
        memset(arr, 0, sizeof arr);
        if(ti) putchar('\n');
    }
    return 0;
}

void backtrack(int dept)
{
    if(dept == len)
    {
        printf("%s\n", pr);
        return;
    }
    for(int i = 0; i < 75; i++)
    {
        if(arr[i] == 0) continue;
        pr[dept] = i + '0';
        arr[i]--;
        backtrack(dept+1);
        backtrack(dept);
        arr[i]++;
    }
    return;
}
