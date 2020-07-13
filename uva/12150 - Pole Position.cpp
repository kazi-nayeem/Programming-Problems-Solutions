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
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int flag[12000];
int main()
{
    int n,u,v;
    while(scanf("%d",&n)==1 && n)
    {
        bool broken=false;
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&u,&v);
            if(v>0)
            {
                if(i+v<=0 || i+v>n)
                broken=true;
                else
                {
                    if(flag[i+v]!=0)
                    broken=true;
                    else
                    flag[i+v]=u;
                }
//                broken=true;
            }
            if(v<0)
            {
                if(i+v<=0 || i+v>n)
                broken=true;
                else
                {
                    if(flag[i+v]!=0)
                    broken=true;
                    else
                    flag[i+v]=u;
                }
//                broken=true;
            }
            if(v==0)
            {
                if(flag[i]!=0)
                broken=true;
                else
                flag[i]=u;
            }

//           else if(flag[u-v]!=0)
//            printf("%d %d \n",u,u-v);
//            flag[i+1]=u-v;
//            else
//            broken=true;
        }
        if(broken)
        cout<<"-1"<<endl;
        else
        {
            for(int i=1;i<n;i++)
            printf("%d ",flag[i]);
            printf("%d\n",flag[n]);
        }
    }


    return 0;
}
