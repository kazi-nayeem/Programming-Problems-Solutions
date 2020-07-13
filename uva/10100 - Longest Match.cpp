#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX1 1001
#define MAX2 21
char str1[MAX1+5], str2[MAX2+5];
int c[MAX1][MAX2];
int len1, len2;

int longcomsub(int i,int j);

int main()
{
    int te = 1, total, mx;
    while(gets(str1))
    {
        len1 = strlen(str1);
        while(gets(str2))
        {
            len2 = strlen(str2);
            if(len2 == 0) break;
            memset(c, -1, sizeof(c));
            mx = longcomsub(0,0);
            printf("%d\n", mx);
            total = 0;
            for(int i = 0; i < len1; i++)
                if(mx == c[i][0])
                    total++;
            //printf("%d. Length of longest match: %d\n", te++, total);
        }
    }
    return 0;
}

int longcomsub(int i,int j)
{
    if(i >= len1 || j >= len2) return 0;
    if(c[i][j] != -1) return c[i][j];
    int p1 = 0, p2 = 0, p3 = 0;
    if(str1[i] == str2[j])
        p1 = longcomsub(i+1, j+1) + 1;
    p2 = longcomsub(i+1,j);
    p3 = longcomsub(i,j+1);
    c[i][j] = max(p1, max(p2,p3));
    return c[i][j];
}

