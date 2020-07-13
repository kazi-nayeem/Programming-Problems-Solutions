#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<assert.h>
#include<time.h>
#include<math.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<25)
#define mp make_pair
#define fs first
#define sc second
#define __ std::ios_base::sync_with_stdio (false)

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}



int main()
{
    int test,n;
    map<string,int> mpp;
    mpp["bit"]=2;
    mpp["dit"]=10;
    int P[105];
    SF("%d",&test);
    string str;
    while(test--)
    {
        SF("%d",&n);
        cin>>str;
        for(int i=0;i<n;i++) SF("%d",&P[i]);
        double din,L,pr,E=0.0;
        if(str=="nat")
        {
            din=1.0;
        }
        else
        {
            din=log(1.0*mpp[str]);
        }
        for(int i=0;i<n;i++)
        {
            if(P[i]==0) continue;
            pr=P[i]/100.0;
            E+=(pr*log(pr)/din);
        }
        PF("%.12lf\n",-E);
    }
    return 0;
}
