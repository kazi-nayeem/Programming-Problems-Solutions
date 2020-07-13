#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char str[100], multi[100];
int len1, len2;


int main()
{
    int flag;
    while(gets(str))
    {
        //puts(str);
        flag = 0;
        len1 = strlen(str);
        for(int i = 2; i <= len1; i++)
        {
            strcpy(multi,str);
            //printf("%s %s\n", str, multi);
            int res = 0;
            for(int j = len1-1; j >= 0; j--)
            {
                res = res+((multi[j]-'0')*i);
                //printf("%d ", res);
                multi[j] = (res%10)+'0';
                res /= 10;
            }
            //printf("\n%d %s\n", i, multi);
            if(res) continue;
            for(int m = 1; m < len1; m++)
                if(str[m] == multi[0])
            {
                flag = 1;
                for(int j = m+1, k = 1; k < len1; k++, j++)
                {
                    j %= len1;
                    if(str[j] != multi[k])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag)
            printf("%s is cyclic\n", str);
        else
            printf("%s is not cyclic\n", str);
    }
    return 0;
}
