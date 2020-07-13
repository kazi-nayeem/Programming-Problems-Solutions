//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

const double PI=acos(-1.0);
const double STD=1e-9;

struct Point
{
    double x,y;
    void disp ()
    {
        printf("x=%lf y=%lf\n",x,y);
    }
    Point friend Vec (Point a,Point b)
    {
        Point res;
        res.x=a.x-b.x;
        res.y=a.y-b.y;
        return res;
    }
};

Point pt[20];

struct Line
{
    Point s,e;
    void set (double sx,double sy,double ex,double ey)
    {
        s.x=sx;
        s.y=sy;
        e.x=ex;
        e.y=ey;
    }
};
Line line[4];

struct Circle
{
    Point c;
    double r;
    bool operator < (const Circle & p) const
    {
        return c.y-r > p.c.y-p.r;
    }
};
struct Rectangle
{
    Point a, b;
};
Circle cir;

int point_num;
bool out[20];

void Find (Line l,int mode)
{
    Point temp;
    double t,d;
    switch (mode)
    {
    case 0:
        if (fabs(cir.c.y-l.s.y) > cir.r)
            return;
        d=cir.c.y-l.s.y;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.y=l.s.y;
        temp.x=cir.c.x-t;
        if (temp.x>l.s.x && temp.x<l.e.x)
            pt[point_num++]=temp;
        temp.x=cir.c.x+t;
        if (temp.x>l.s.x && temp.x<l.e.x)
            pt[point_num++]=temp;
        break;
    case 1:
        if (fabs(cir.c.x-l.s.x) > cir.r)
            return;
        d=cir.c.x-l.s.x;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.x=l.s.x;
        temp.y=cir.c.y+t;
        if (temp.y<l.s.y && temp.y>l.e.y)
            pt[point_num++]=temp;
        temp.y=cir.c.y-t;
        if (temp.y<l.s.y && temp.y>l.e.y)
            pt[point_num++]=temp;
        break;
    case 2:
        if (fabs(cir.c.y-l.s.y) > cir.r)
            return;
        d=cir.c.y-l.s.y;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.y=l.s.y;
        temp.x=cir.c.x+t;
        if (temp.x<l.s.x && temp.x>l.e.x)
            pt[point_num++]=temp;
        temp.x=cir.c.x-t;
        if (temp.x<l.s.x&&temp.x>l.e.x)
            pt[point_num++]=temp;
        break;
    case 3:
        if (fabs(cir.c.x-l.s.x) > cir.r)
            return;
        d=cir.c.x-l.s.x;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.x=l.s.x;
        if (l.s.y<l.e.y)
            temp.y=cir.c.y-t;
        if (temp.y>l.s.y && temp.y<l.e.y)
            pt[point_num++]=temp;
        temp.y=cir.c.y+t;
        if (temp.y>l.s.y && temp.y<l.e.y)
            pt[point_num++]=temp;
    }
}
/*
void Find (Line l)
{
    Point temp;
    double t,d;
    if (fabs(l.s.x-l.e.x) < STD)
    {
        if (fabs(cir.c.x-l.s.x) > cir.r)
            return;
        d=cir.c.x-l.s.x;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.x=l.s.x;
        if (l.s.y<l.e.y)         {
            temp.y=cir.c.y-t;
            if (temp.y>l.s.y && temp.y<l.e.y)
                pt[point_num++]=temp;
            temp.y=cir.c.y+t;
            if (temp.y>l.s.y && temp.y<l.e.y)
                pt[point_num++]=temp;
        }
        else        {
            temp.y=cir.c.y+t;
            if (temp.y<l.s.y && temp.y>l.e.y)
                pt[point_num++]=temp;
            temp.y=cir.c.y-t;
            if (temp.y<l.s.y && temp.y>l.e.y)
                pt[point_num++]=temp;
        }
    }
    else
    {
        if (fabs(cir.c.y-l.s.y) > cir.r)
            return;
        d=cir.c.y-l.s.y;
        t=sqrt(fabs(cir.r*cir.r-d*d));
        temp.y=l.s.y;
        if (l.s.x<l.e.x)
        {
            temp.x=cir.c.x-t;
            if (temp.x>l.s.x && temp.x<l.e.x)
                pt[point_num++]=temp;
            temp.x=cir.c.x+t;
            if (temp.x>l.s.x && temp.x<l.e.x)
                pt[point_num++]=temp;
        }
        else
        {
            temp.x=cir.c.x+t;
            if (temp.x<l.s.x && temp.x>l.e.x)
                pt[point_num++]=temp;
            temp.x=cir.c.x-t;
            if (temp.x<l.s.x&&temp.x>l.e.x)
                pt[point_num++]=temp;
        }
    }
}*/

void Input (Circle circlein, Rectangle rec)
{
    //scanf("%lf%lf%lf",&cir.c.x,&cir.c.y,&cir.r);
    cir = circlein;
    double lx = rec.a.x,ly = rec.a.y,rx = rec.b.x,ry = rec.b.y;
    //scanf("%lf%lf%lf%lf",&lx,&ly,&rx,&ry);

    line[0].set(lx,ry,rx,ry);
    line[1].set(rx,ry,rx,ly);
    line[2].set(rx,ly,lx,ly);
    line[3].set(lx,ly,lx,ry);

    point_num=0;
    pt[point_num++]=line[0].s;
    Find (line[0],0);
    pt[point_num++]=line[1].s;
    Find (line[1],1);
    pt[point_num++]=line[2].s;
    Find (line[2],2);
    pt[point_num++]=line[3].s;
    Find (line[3],3);

//  for (int i=0;i<point_num;i++) printf("Point %d ",i),pt[i].disp();
}

double get_dis (Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double get_dis2 (Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void Judge ()
{
    double t;
    for (int i=0; i<point_num; i++)
    {
        t=get_dis(pt[i],cir.c);
        if (t>cir.r+STD)
            out[i]=true;
        else out[i]=false;
    }
}

double get_cj (Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double get_dj(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}


double get_tri (Point a,Point b)
{
    return get_cj (Vec(a,cir.c),Vec(b,cir.c))/2;
}

double get_sec (Point a,Point b)
{
    double da=get_dis2 (a,cir.c);
    double db=get_dis2 (b,cir.c);
    double cj=get_cj (Vec(a,cir.c),Vec(b,cir.c));
    double dj=get_dj (Vec(a,cir.c),Vec(b,cir.c));
    double dsin=cj/sqrt(da*db);
    double alpha=asin(dsin);


    if (dj < -STD)
        if (alpha>0)
            alpha=PI-alpha;
        else
            alpha=-PI-alpha;

    return alpha*cir.r*cir.r/2;
}

double Deal ()
{
    if (cir.r < STD)
        return 0;
    Judge ();

    double ans=0;
    for (int i=0; i<point_num; i++)
    {
        if (out[i] == false && out[(i+1)%point_num] == false)
            ans+=get_tri(pt[i],pt[(i+1)%point_num]);
        else
            ans+=get_sec(pt[i],pt[(i+1)%point_num]);
    }
    return fabs(ans);
}


double get_area(Circle c, int x1, int y1, int x2, int y2)
{
    Rectangle rec;
    rec.a.x = min(x1,x2);
    rec.b.x = max(x1,x2);
    rec.a.y = min(y1,y2);
    rec.b.y = max(y1,y2);
    Input(c,rec);
    return Deal();
}

#define MX 100005

struct data_query
{
    int y, x1, x2, pos, ty;
    bool operator < (const data_query & p) const
    {
        return y>p.y;
    }
};

double tree[MX*4];

void update_tree(int node, int beg, int en, int pos, double val)
{
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos)
    {
        tree[node] += val;
        return;
    }
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update_tree(left,beg,mid,pos,val);
    update_tree(right,mid+1,en,pos,val);
    tree[node] = (tree[left]+tree[right]);
}

double query_tree(int node, int beg, int en, int i, int j)
{
    if(beg > j || i > en) return 0;
    if(i <= beg && en <= j)
        return tree[node];
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    double ans = query_tree(left,beg,mid,i,j);
    ans += query_tree(right,mid+1,en,i,j);
    return ans;
}

data_query query[MX*2];
Circle topcircle[MX];
queue<Circle> currentcir;
int xcoordi[MX*2], totxx;
int query_test;
int circle_test;

int find_pos(int val)
{
    int pos = lower_bound(xcoordi,xcoordi+totxx,val)-xcoordi;
    return pos;
}

void update(int pre, int now)
{
    while(circle_test>=0)
    {
        Circle c = topcircle[circle_test];
        if(now>=c.c.y-c.r)
        {
            currentcir.push(c);
            circle_test--;
        }
        else
            break;
    }
    queue<Circle> newqu;
    while(!currentcir.empty())
    {
        Circle ci = currentcir.front();
        currentcir.pop();
        if(ci.c.y+ci.r>now)
            newqu.push(ci);
        int pos = find_pos(ci.c.x-ci.r);
        while(xcoordi[pos-1] < ci.c.x+ci.r)
        {
            double area = get_area(ci,xcoordi[pos-1],pre,xcoordi[pos],now);
            if(area>0.0)
                update_tree(1,0,totxx,pos,area);
            pos++;
        }
        //ci.c.disp();
    }
    currentcir = newqu;
}

double res[MX][2];

void process()
{
    int prev = -MX;
    while(query_test>=0)
    {
        data_query q = query[query_test];
        query_test--;
        if(q.y>prev)
        {
            update(prev,q.y);
            prev = q.y;
        }
        //printf("------%d %d %d\n", q.y, q.ty, q.pos);
        res[q.pos][q.ty] = query_tree(1,0,totxx,find_pos(q.x1)+1,find_pos(q.x2));
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    circle_test = 0;
    for(int i = 0; i < n; i++)
    {
        Circle ci;
        scanf("%lf %lf %lf", &ci.c.x, &ci.c.y, &ci.r);
        topcircle[circle_test++] = ci;
    }
    sort(topcircle,topcircle+circle_test);
    circle_test--;
    int x1, y1, x2, y2;
    totxx = 0;
    query_test = 0;
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        data_query tem;
        tem.pos = i;
        tem.x1 = x1;
        tem.x2 = x2;
        tem.ty = 0;
        tem.y = y1;
        query[query_test++] = tem;
        tem.y = y2;
        tem.ty = 1;
        query[query_test++] = tem;

        xcoordi[totxx++] = tem.x1;
        xcoordi[totxx++] = tem.x2;
    }
    sort(query,query+query_test);
    query_test--;
    xcoordi[totxx++] = MX;
    xcoordi[totxx++] = -MX;
    sort(xcoordi,xcoordi+totxx);

    int tem = totxx;
    totxx = 0;
    for(int i = 1; i < tem; i++)
    {
        if(xcoordi[totxx] != xcoordi[i])
            xcoordi[++totxx] = xcoordi[i];
    }
    totxx++;
//    for(int i = 0; i < totxx; i++)
//        printf("---%d\n", xcoordi[i]);
    process();
    for(int i = 0; i < q; i++)
        printf("%.12lf\n", res[i][1]-res[i][0]);
    return 0;
}

/*
2
4 4 4
1 1 3 3
4 4 4
1 1 7 7

Out
Case 1: 3.93987658
Case 2: 35.75950633
*/
