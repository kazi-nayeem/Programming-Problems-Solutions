#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100000

int parent[MX];

int findpar(const int n)
{
    if(parent[n] == n) return n;
    return parent[n] = findpar(parent[n]);
}


int main()
{
    char str[50];
    int len, time, co, inc, node, a, b;

    scanf("%d", &time);

    while(time--)
    {
        co = 0, inc = 0;

        scanf(" %d", &node);
        getchar();

        for(int i = 0; i <= node; i++)
            parent[i] = i;

        while(gets(str))
        {
            len = strlen(str);
            if(len == 0) break;

            sscanf(str+1, " %d %d", &a, &b);

            a = findpar(a);
            b = findpar(b);

            if(str[0] == 'c')
            {
                if(a != b)
                    parent[a] = b;
                continue;
            }
            if(str[0] == 'q')
            {
                if(a == b) co++;
                else inc++;
            }
        }
        printf("%d,%d\n", co, inc);
        if(time)
            putchar('\n');
    }
    return 0;
}
