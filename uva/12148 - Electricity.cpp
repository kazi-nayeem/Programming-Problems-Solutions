#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#define PI (2* acos(0))
#define pb push_back
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};

#define  lli long long int
lli n;
lli pd,pm,py,pc;
lli d,m,y,c;
int main()
{
    lli tn;
    lli ans;
    lli consum;
    while(scanf("%lld",&n)==1 && n!=0 ){
        tn = n;
        ans = 0;
        consum = 0;
        pd = pm = py = pc = 0;
        while(tn--){
            scanf("%lld %lld %lld %lld",&d,&m,&y,&c);
            if(pd||pm||py||pc){
               if( (d-pd)==1 && (m-pm)==0 && (y-py)==0){
                   ans++;
                   consum += c-pc;
               }
               else if((pm==1&&m==2&&pd==31&&d==1&&(y-py)==0)
                       || (pm==3&&m==4&&pd==31&&d==1&&(y-py)==0)
                       || (pm==4&&m==5&&pd==30&&d==1&&(y-py)==0)
                       ||  (pm==2 && m==3 && pd==29 && d==1 &&(y-py)==0)
                       || (pm==5&&m==6&&pd==31&&d==1&&(y-py)==0)
                       || (pm==6&&m==7&&pd==30&&d==1&&(y-py)==0)
                       || (pm==7&&m==8&&pd==31&&d==1&&(y-py)==0)
                       || (pm==8&&m==9&&pd==31&&d==1&&(y-py)==0)
                       || (pm==9&&m==10&&pd==30&&d==1&&(y-py)==0)
                       || (pm==10&&m==11&&pd==31&&d==1&&(y-py)==0)
                       || (pm==11&&m==12&&pd==30&&d==1&&(y-py)==0)
                       || (pm==12 && m==1 && pd==31 && d==1 &&(y-py)==1)
                       ){
                    ans++;
                    consum += c-pc;
                }
               else if ((pm==2&&m==3&&pd==28&&d==1&&(y-py)==0) && ( (y%4)!=0 || (y%100)==0) && (y%400)!=0){
                    ans++;
                    consum += c-pc;
               }
            }
            pm = m;
            pd = d;
            py =y;
            pc = c;
        }


        printf("%lld %lld\n",ans,consum);


    }

    return 0;
}

