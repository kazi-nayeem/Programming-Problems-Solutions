#include<cstdio>
#include<iostream>
using namespace std;

struct point{
	long long x,y;
};
struct line{
	point s,e;
	line(point a, point b)
	{
        s = a;
        e = b;
	}
};

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

point arr[205];
ll dp[205][205];

int main()
{
    memset(dp,-1,sizeof dp);
}

