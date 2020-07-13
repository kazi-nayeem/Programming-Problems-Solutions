#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 2000005

int main()
{
    int len, mini;
    char arr[MX];
    while(scanf("%d", &len) == 1)
    {
        if(len == 0) return 0;
        getchar();
        gets(arr);
        mini = MX+1;
        for(int i = 0; i < len; i++)
        {
            if(arr[i] == 'Z')
            {
                mini = 0;
                break;
            }
            if(arr[i] == 'D')
            {
                for(int j = i-1; j >= 0; j--)
                {
                    if(arr[j] == 'R')
                    {
                        int k = i - j;
                        if(k < mini)
                            mini = k;
                        break;
                    }
                    if(arr[j] != '.') break;
                }
                for(int j = i+1; j < len; j++)
                {
                    if(arr[j] == 'R')
                    {
                        int k = j - i;
                        if(k < mini)
                            mini = k;
                        break;
                    }
                    if(arr[j] != '.') break;
                }
            }
        }
        printf("%d\n", mini);
    }
    return 0;
}
