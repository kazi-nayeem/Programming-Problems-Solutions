#include <stack>
#include <cstdio>
#include <algorithm>

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define clr(name,val) memset(name,(val),sizeof(name));
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS .000000001
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("outputtest.txt","w",stdout)

using namespace std;

struct pii{
    int x, y, pos;
};

pii point[2005];

int n;///n should be greater than 2;
int cross(pii b,pii c)
{
    return b.x*c.y-b.y*c.x;
}

bool comp1(pii a,pii b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

ll distance(pii a)
{
    ll d =(ll) a.x*(ll) a.x + (ll) a.y*(ll) a.y;
    return d;
}

bool comp2(pii a,pii b)
{
    a.x-=point[0].x;
    b.x-=point[0].x;
    a.y-=point[0].y;
    b.y-=point[0].y;
    int crs=cross(a,b);
    if(crs==0)
    {
        return distance(a)<distance(b);
    }
    else return crs>0;
}

/*stack<pii > S;

void convex_Hull()
{
    pii x,a,b,na,nb;
    bool ok;
    for(int i=2; i<n; i++)
    {
        ok=true;
        b=point[i];
        if(col[i]) continue;
        do
        {
            a=S.top(),S.pop();
            x=S.top(),S.pop();
            S.push(x);
            S.push(a);
            na=a,nb=b;
            na.x-=x.x;
            nb.x-=x.x;
            na.y-=x.y;
            nb.y-=x.y;
            int crs=cross(na,nb);
            if(crs==0)
            {
                ok=false;
                break;
            }
            else if(crs>0) break;
            else
            {
                if(SZ(S)>2)
                    S.pop();
                else break;
            }
        }
        while(SZ(S)>2);
        if(ok) S.push(b);
    }
    return ;
}*/

pii a,b;

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &point[i].x, &point[i].y);
            point[i].pos = i;
        }
        sort(point,point+n,comp1);

        sort(point+1,point+n,comp2);
//        cout<<"::::::::::::::::"<<endl;
        /*for(int i=2; i<n; i++)
        {
            a=point[i];
            b=point[i-1];
            a.x-=x;
            b.x-=x;
            a.y-=y;
            b.y-=y;
            int crs=cross(a,b);
            if(crs==0) col[i]=true;
        }*/
//        for(int i=0;i<n;i++)
//        {
//            cout<<point[i].fs<<" "<<point[i].sc<<endl;
//        }

        //S.push(point[0]);
        //S.push(point[1]);
//        cout<<"Convex Hull Set of Points"<<endl;
//        cout<<"::::::::::::::::"<<endl;
        //convex_Hull();
        int flag = 0;
        for(int i = n-2; i > 0; i--)
        {
            a=point[i];
            b=point[n-1];
            a.x-=point[0].x;
            b.x-=point[0].x;
            a.y-=point[0].y;
            b.y-=point[0].y;
            int crs=cross(a,b);
            if(crs != 0)
            {
                flag = i;
                break;
            }
        }

        printf("Case %d:\n", te);
        if(flag == 0)
        {
            printf("Impossible");
        }
        else
        {
            //printf("%d\n", flag);
            reverse(point+flag+1,point+n);
            printf("%d", point[0].pos);
            for(int i = 1; i < n; i++)
                printf(" %d", point[i].pos);
        }
        puts("");
        //        cout<<x<<" "<<y<<endl;
        /*while(!S.empty())
        {
//            cout<<S.top().fs<<" "<<S.top().sc<<endl;
            S.pop();
        }*/
//        cout<<"::::::::::::::::"<<endl;
    }
    return 0;
}


/*
6
4
0 0
1 1
2 2
0 1
4
0 0
1 1
2 2
1 0
*/














