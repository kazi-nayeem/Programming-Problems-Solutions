/* ***********************************************
Author        :kuangbin
Created Time  :2014/4/22 17:41:27
File Name     :E:\2014ACMLightOJ1285.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxp = 2010;
struct Point
{
    int x,y;
    int index;
    Point(){}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    void input()
    {
        scanf("%d%d",&x,&y);
    }
    bool operator < (Point b)const
    {
        return x == b.x ? y < b.y:x < b.x;
    }
    Point operator - (const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    int len2()
    {
        return x*x + y*y;
    }
};
Point p[maxp];
bool cmp(Point a,Point b)
{
    int tt = (a-p[0])^(b-p[0]);
    if(tt == 0)
        return (a-p[0]).len2() < (b-p[0]).len2();
    else return tt > 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            p[i].input();
            p[i].index = i;
        }
        sort(p,p+n);
        sort(p+1,p+n,cmp);
        int tmp = 0;
        for(int i = n-2;i > 0;i--)
            if(( (p[n-1]-p[0])^(p[i]-p[0]) ) != 0)
            {
                tmp = i;
                break;
            }
        printf("Case %d:\n",iCase);
        if(tmp == 0)
            printf("Impossible\n");
        else
        {
            reverse(p+tmp+1,p+n);
            for(int i = 0;i < n;i++)
            {
                printf("%d",p[i].index);
                if(i < n-1)printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
