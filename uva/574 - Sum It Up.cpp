#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

int n, num, flag;
int number[15];
vector<int > total;
int tak[15];

void backtrack(int sum,int pos);

int main()
{
    while(scanf("%d %d" , &n, &num) == 2)
    {
        if(n == 0 && num == 0) return 0;

        for(int i = 0; i < num; i++)
            scanf("%d", &number[i]);

        flag = 1;
        total.clear();
        printf("Sums of %d:\n", n);
        backtrack(0,0);

        if(flag) puts("NONE");
    }
    return 0;
}

void backtrack(int sum,int pos)
{
    if(sum == n)
    {
        int sz = total.size();
        for(int i = 0; i < sz; i++)
        {
            if(i) putchar('+');
            printf("%d", total[i]);
        }
        putchar('\n');
        flag = 0;
    }

    for(int i = pos; i < num; i++)
    {
        if(i>0)
            if(number[i] == number[i-1] && tak[i-1] == 0) continue;
        int k = sum + number[i];
        if(k <= n)
        {
            tak[i] = 1;
            total.push_back(number[i]);
            backtrack(k,i+1);
            total.pop_back();
            tak[i] = 0;
        }
    }
    return;
}
