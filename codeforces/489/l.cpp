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
using namespace std ;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
5
5 6
100001
100000
000001
011001
000101

#define Max 1000
#define lli long long int

lli r,c,ans;
lli mat[Max][Max],row,col;

int main()
{
    lli t,a;
    char temp[1500];

    scanf("%lld",&t);

    for(a=1; a<=t; a++)
    {
        scanf("%lld %lld",&r,&c);

        for(lli i=1; i<=r; i++)
        {
            scanf("%s",temp);
            for(lli j=1; j<=c; j++)
            {
               // scanf("%lld",&mat[i][j]);
                mat[i][j]=temp[j-1] -'0';
            }
        }
/*
        for(lli i=1;i<=r;i++){
            for(lli j=1;j<=c;j++){
                cout<<mat[i][j]<<"  ";
            }
            cout<<'\n';

        }
*/
        for(lli i=1; i<=r; i++)
        {
            for(lli j=1; j<=c; j++)
            {
                if(mat[i][j]==1)
                {
                    col=row=0;
                    for(lli k=1; k<=r; k++)
                    {
                        col+=mat[k][j];
                    }
                    for(lli k=1; k<=c; k++)
                    {
                        row+=mat[i][k];
                    }
                    ans++;
                    if(col>=row)
                    {
                        for(lli k=1; k<=r; k++)
                        {
                            mat[k][j]=0;
                        }
                    }
                    else
                    {
                        for(lli k=1; k<=c; k++)
                        {
                            mat[i][k]=0;
                        }
                    }
                }
            }
        }
/*
        for(lli i=1;i<=r;i++){
            for(lli j=1;j<=c;j++){
                cout<<mat[i][j]<<"  ";
            }
            cout<<'\n';

        }
*/
        printf("Case #%lld: %lld\n",a,ans);
        ans=0;
    }


    return 0;
}
/*
5
5 6
100001
100000
000001
011001
000101
*/
