#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 1001

char str1[MAX+5], str2[MAX+5];
int c[MAX][MAX];
int len1, len2;

int longcomsub(int i,int j);

int main()
{
    while(gets(str1))
    {
        gets(str2);
        len1 = strlen(str1);
        len2 = strlen(str2);

        memset(c, -1, sizeof(c));

        printf("%d\n", longcomsub(0,0));
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

