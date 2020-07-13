#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-9
#define SZ(s)       (int)s.size()
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=xusing namespace std;
//Vector or point2d
#define vectorVar int //change should be done here for different datatype

struct Vector {
    vectorVar  x,y;
    Vector(vectorVar  x1=0,vectorVar  y1=0) {
        x=x1;
        y=y1;
    }

    int scan() {
        return scanf("%lf %lf",&x,&y);
    }
    int scanint() {
        return scanf("%d %d",&x,&y);
    }
    int scanLL() {
        return scanf("%lld %lld",&x,&y);
    }
    void print() {
        print2(x,y);
    }

    Vector negate() {
        return Vector(-x,-y);
    }
    vectorVar length() {
        return sqrt(x*x+y*y);
    }
    vectorVar sqrLength() {
        return x*x+y*y;
    }
    vectorVar length(Vector b) { //from a to b and vice versa
        Vector tem(x-b.x,y-b.y);
        return tem.length();
    }
    vectorVar angle() { //(-pi to +pi)  (for all angles)
        vectorVar  ret=atan2(y,x);
        return ret;
    }
    vectorVar angle(Vector b) { //(0 to +pi)
        vectorVar  ret=dot(b)/(length()*b.length());
        if(ret<-1) ret=-1;
        if(ret>1) ret=1;
        return acos(ret);
    }
    vectorVar angleWithSign(Vector b) { //(-pi to +pi)  (a to b)
        if(cross(b)>0) return angle(b);
        return -angle(b);
    }
    Vector add(Vector b) {
        return Vector(x+b.x,y+b.y);
    }
    Vector substract(Vector b) {
        return Vector(x-b.x,y-b.y);
    }
    vectorVar dot(Vector b) {
        return x*b.x+y*b.y;
    }
    //negative means b is clockwise to main vector
    vectorVar  cross(Vector b) {
        return x*b.y-b.x*y;
    }
    //a is fixed
    vectorVar cross(Vector a,Vector b) { //now to b
        Vector now;
        now=substract(a);
        b=b.substract(a);
        return now.cross(b);
    }
    //for unit vector l=1
    Vector lengthTransform(vectorVar l) {
        vectorVar  len=length();
        return  Vector(x*l/len,y*l/len);
    }
    Vector rotation(vectorVar theta) {
        return Vector(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
    }

    Vector shortestPoint(Vector b) { //make point a vector //distance from point to line
        vectorVar len=dot(b)/length();
        Vector ret=lengthTransform(len);
        if(ret.x>max(0,x)||ret.x<min(0,x)) {
            ret.x=0;
            ret.y=0;
            if(b.length()<length(b))  return ret;
            ret.x=x;
            ret.y=y;
            return ret;
        }
        if(ret.y>max(0,y)||ret.y<min(0,y)) {
            ret.x=0;
            ret.y=0;
            if(b.length()<length(b))  return ret;
            ret.x=x;
            ret.y=y;
            return ret;
        }
        return ret;
    }

    vectorVar shortestDist(Vector b) { //make point a vector //distance from point to line
        vectorVar len=dot(b)/length();
        Vector ret=lengthTransform(len);
        if(ret.x>max(0,x)||ret.x<min(0,x))
            return min(b.length(),length(b));

        if(ret.y>max(0,y)||ret.y<min(0,y))
            return min(b.length(),length(b));
        ret=ret.substract(b);
        return ret.length();
    }
};
typedef Vector Point;
Vector operator + (Vector a, Vector b) {
    return Vector(a.x+b.x, a.y+b.y);
}
Vector operator - (Vector a, Vector b) {
    return Vector(a.x-b.x, a.y-b.y);
}
Vector operator * (Vector a, double p) {
    return Vector(a.x*p, a.y*p);
}
Vector operator / (Vector a, double p) {
    return Vector(a.x/p, a.y/p);
}
//this are used for set compare
int dcmp(double x) { //precise up to ERR
    if(fabs(x)<ERR)return 0;
    else return x<0?-1:1;
}

struct triangle {
    Point a,b,c;
    triangle(Vector a1=0,Vector b1=0, Vector c1=0) {
        a=a1;
        b=b1;
        c=c1;
    }
    //a is fixed
    //.5 should be omitted in case of integer counting
    double areaWithoutSign() {
        Vector p=b.substract(a);
        Vector q=c.substract(a);
        return fabs(.5*p.cross(q));
    }
    //a is fixed
    //.5 should be omitted in case of integer counting
    vectorVar areaWithSign() {
        Vector p=b.substract(a);
        Vector q=c.substract(a);
        return .5*p.cross(q);
    }
};

double areaOfPolygon(Vector poly[],int n) {
    int i;
    double area=0;
    for(i=2; i<n; i++) {
        triangle tem(poly[1],poly[i],poly[i+1]);
        area+=tem.areaWithSign();
    }
    return fabs(area);
}

Vector arr[1000];
Vector s[1000];

bool mult(Point sp,Point ep,Point op) {
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}

bool operator < (const Point& l,const Point& r) {
    return l.y<r.y||(l.y==r.y&&l.x<r.x);
}

//0 based
//res[0] and res[last] are same
int graham(Point pnt[],int n,Point res[]) {
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0;
    res[0]=pnt[0];
    if(n==1) return 1;
    res[1]=pnt[1];
    if(n==2) return 2;
    res[2]=pnt[2];
    for(i=2; i<n; i++) {
        while(top&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3; i>=0; i--) {
        while(top!=len&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    return top;
}

double dp[102][102][102];
int cas[102][102][102];
int total, mxtk, now;

double func(int a, int tk, int pos) {
    if(tk == mxtk) return 0;
    double & res = dp[a][tk][pos];
    int & ts = cas[a][tk][pos];
    if(ts == now) return res;
    res = 0;
    ts = now;
    for(int i = pos+1; i < total; i++) {
        triangle tem = triangle(s[a],s[pos],s[i]);
        res = max(res,func(a,tk+1,i)+tem.areaWithoutSign());
    }
    return res;
}

int main() {
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%d %d", &n, &mxtk);
        int i;
        fr(i,0,n-1) arr[i].scanint();
        total = graham(arr,n,s);
        //for(int i = 0; i <= total; i++)
        //  s[i].print();
        //printf("%d\n", total);
        now++;
        double ans = 0.0;
        //printf("%lf\n", triangle(s[0],s[1],s[2]));
        for(int i = 0; i < total; i++)
            for(int j = i+1; j < total; j++)
            ans = max(ans,func(i,2,j));
        printf("Case %d: %.3lf\n", te, ans);
    }
    return 0;
}
/*
4
6 7
8 6
4 3
1 2
ans=4

15
0 0
0 0
0 0
-3 0
-3 0
-3 0
3 0
3 0
3 0
0 -1
0 -1
0 -1
0 1
0 1
0 1
4
2 2
2 -2
-2 -2
-2 2
*/
