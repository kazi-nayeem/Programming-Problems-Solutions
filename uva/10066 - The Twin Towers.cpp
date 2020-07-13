#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100

int num1, num2, arr1[MAX], arr2[MAX];
int com[MAX][MAX];

int func(int i, int j);

int main()
{
    int te = 1;
    while(scanf("%d %d", &num1, &num2) == 2)
    {
        if(num1 == 0 && num2 == 0) return 0;

        memset(com, -1, sizeof(com));

        for(int i = 0; i < num1; i++)
            scanf(" %d", &arr1[i]);
        for(int i = 0; i < num2; i++)
            scanf(" %d", &arr2[i]);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", te++, func(0,0));
    }
}

int func(int i, int j)
{
    if(i >= num1 || j >= num2) return 0;

    if(com[i][j] != -1) return com[i][j];
    int p1 = 0, p2, p3;
    if(arr1[i] == arr2[j])
        p1 = func(i+1, j+1)+1;
    p2 = func(i+1,j);
    p3 = func(i,j+1);

    p1 = (p1 < p2)? p2 : p1;
    com[i][j] = (p1 < p3)? p3:p1;
    return com[i][j];
}
