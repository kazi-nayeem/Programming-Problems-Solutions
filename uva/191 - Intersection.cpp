#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct{
	long long x,y;
} point;
typedef struct{
	point s,e;
}line;
long long direction(point p0,point p1, point p2){
	return (((p2.x-p0.x)*(p1.y-p0.y))-((p1.x-p0.x)*(p2.y-p0.y)));
}
bool on_segment(point pi,point pj,point pk){
	if((min(pi.x,pj.x)<=pk.x && pk.x<=max(pi.x,pj.x)) &&
	   (min(pi.y,pj.y)<=pk.y && pk.y<=max(pi.y,pj.y)) )
		return true;
	return false;
}
bool segment_intersect(point p1,point p2,point p3,point p4){
	long long d1,d2,d3,d4;
	d1=direction(p3,p4,p1);
	d2=direction(p3,p4,p2);
	d3=direction(p1,p2,p3);
	d4=direction(p1,p2,p4);
	if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&
	   ((d3>0 && d4<0) || (d3<0 && d4>0)))
		return true;
	else if(d1==0 && on_segment(p3,p4,p1))
		return true;
	else if(d2==0 && on_segment(p3,p4,p2))
		return true;
	else if(d3==0 && on_segment(p1,p2,p3))
		return true;
	else if(d4==0 && on_segment(p1,p2,p4))
		return true;
	return false;
}
bool line_intersect(line a, line b){
    return segment_intersect(a.s,a.e,b.s,b.e);
}

int main()
{
    long long int x1, x2, y1, y2;
    line x, rec;
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%lld %lld %lld %lld", &x.s.x, &x.s.y, &x.e.x, &x.e.y);
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if((x.s.x <= max(x1,x2) && x.s.x >= min(x1,x2)) && (x.s.y <= max(y1,y2) && x.s.y >= min(y1,y2)))
        {
            printf("T\n");
            continue;
        }

        if((x.e.x <= max(x1,x2) && x.e.x >= min(x1,x2)) && (x.e.y <= max(y1,y2) && x.e.y >= min(y1,y2)))
        {
            printf("T\n");
            continue;
        }
        line tem;
        tem.s.x = x1;
        tem.e.x = x1;
        tem.s.y = y1;
        tem.e.y = y2;
        if(line_intersect(x,tem))
        {
            printf("T\n");
            continue;
        }
        tem.s.x = x2;
        tem.e.x = x2;
        tem.s.y = y1;
        tem.e.y = y2;
        if(line_intersect(x,tem))
        {
            printf("T\n");
            continue;
        }
        tem.s.x = x1;
        tem.e.x = x2;
        tem.s.y = y1;
        tem.e.y = y1;
        if(line_intersect(x,tem))
        {
            printf("T\n");
            continue;
        }
        tem.s.x = x1;
        tem.e.x = x2;
        tem.s.y = y2;
        tem.e.y = y2;
        if(line_intersect(x,tem))
        {
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
    return 0;
}
