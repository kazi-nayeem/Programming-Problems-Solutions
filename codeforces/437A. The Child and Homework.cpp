#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

char arr[4][105];
int len[4];
int flag[4];

int main()
{
    char ch[5];
    for(int i = 0; i < 4; i++)
    {
        scanf("%2s%s", ch, arr[i]);
        len[i] = strlen(arr[i]);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            if((i != j) && (len[i] < (2*len[j]))) flag[i] = 1;
        if(flag[i] == 0) continue;
        flag[i] = 0;
        for(int j = 0; j < 4; j++)
            if(i != j && ((2*len[i]) > len[j])) flag[i] = 1;
    }
    int ans = 0, a;
    for(int i = 0; i < 4; i++)
        if(flag[i] == 0) ans++, a = i;
    if(ans == 1)
        printf("%c\n", 'A'+a);
    else
        printf("C\n");
    return 0;
}
