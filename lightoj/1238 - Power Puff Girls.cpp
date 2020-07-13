#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

#define MAX 23

typedef struct st{int i, j, dis;} pairof;

char super[MAX][MAX];
int distence[MAX][MAX];
int row, colum;

void bfs(int i, int j);


int main()
{
    int time, test;
    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &row, &colum);
        getchar();
        for(int i = 0; i < row; i++)
            gets(super[i]);
        char ch;
        pairof home, aposi, bposi, cposi;
        for(int i = 0, j; i < row; i++)
            for(j = 0; j < colum; j++)
        {
            ch = super[i][j];
            if(ch == 'h')
            {
                home.i = i;
                home.j = j;
            }
            if(ch == 'a')
            {
                aposi.i = i;
                aposi.j = j;
                super[i][j] = '.';
            }
            if(ch == 'b')
            {
                bposi.i = i;
                bposi.j = j;
                super[i][j] = '.';
            }
            if(ch == 'c')
            {
                cposi.i = i;
                cposi.j = j;
                super[i][j] = '.';
            }
        }

        bfs(home.i, home.j);

        int maxi;
        maxi = distence[aposi.i][aposi.j];
        if(maxi < distence[bposi.i][bposi.j])
            maxi = distence[bposi.i][bposi.j];
        if(maxi < distence[cposi.i][cposi.j])
            maxi = distence[cposi.i][cposi.j];

        printf("Case %d: %d\n", test, maxi);
    }
    return 0;
}

void bfs(int i, int j)
{
    memset(distence,0,sizeof distence);
    queue<pairof> next;
    pairof temp;
    int diff;

    temp.i = i;
    temp.j = j;
    temp.dis = 0;

    next.push(temp);

    distence[i][j] = 1;

    while(next.size())
    {
        temp = next.front();
        next.pop();
        i = temp.i;
        j = temp.j;
        diff = temp.dis;
        if(i>0)
        {
            if(distence[i-1][j] == 0 && super[i-1][j] == '.')
            {
                temp.i = i - 1;
                temp.j = j;
                temp.dis = diff + 1;

                next.push(temp);

                distence[i-1][j] = diff+1;
            }
        }
        if(j>0)
        {
            if(distence[i][j-1] == 0 && super[i][j-1] == '.')
            {
                temp.i = i;
                temp.j = j-1;
                temp.dis = diff + 1;

                next.push(temp);

                distence[i][j-1] = diff+1;
            }
        }
        if(j+1<colum)
        {
            if(distence[i][j+1] == 0 && super[i][j+1] == '.')
            {
                temp.i = i;
                temp.j = j+1;
                temp.dis = diff + 1;

                next.push(temp);

                distence[i][j+1] = diff+1;
            }
        }
        if(i+1<row)
        {
            if(distence[i+1][j] == 0 && super[i+1][j] == '.')
            {
                temp.i = i+1;
                temp.j = j;
                temp.dis = diff + 1;

                next.push(temp);

                distence[i+1][j] = diff+1;
            }
        }
    }

    return;
}

