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
#define push_back pb
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
char grid[250][250];
bool colcheck(int D,int ind)
{
    for(int i=0; i<ind; i++)
    {
        if(strlen(grid[i])!=D+2)
            return false;
    }
    return true;
}
int main()
{
//    set<int>S;
//    S.insert();
//    S.insert();
//    S.insert();
//    S.insert();
//    S.insert();

    char arr[250];
    int t;
    scanf("%d",&t);
    getchar();
    for(int cs=1; cs<=t; cs++)
    {
        int ind=0;
        int flag=0;
        while(gets(arr) && strcmp(arr,"*") )
        {
//            if(!strcmp(arr,""))
//            continue;
            for(int i=strlen(arr)-1;i>=0;i--)
            {
                if(arr[i]==' ')
                arr[i]=0;
            }
            strcpy(grid[ind++],arr);

        }
        int D= (ind-3)/2;
//                    printf("%d\n",D);

        if(ind<3 || ind%2!=1)
        {
//            puts("ffa");
            flag=1;
        }
        else if(!colcheck(D,ind))
        {
//            printf("da");
            flag=1;
        }
        else
        {


            for(int i=0; i<ind; i++)
            {
                if(i!=0 && i!=D+1 && i!=D+1+D+1)
                {



                    if(grid[i][0]!='|' || grid[i][D+1]!='|' )
                    {
                        flag=1;
                        break;
                    }

                }
                else
                {
                    if(grid[i][0]!='.' || grid[i][D+1]!='.' )
                    {
                        flag=1;
                        break;
                    }

                }
            }
            for(int i=0; i<ind; i++)
            {
                for(int j=1; j<D+1; j++)
                {
                    if(i!=0 && i!=D+1 && i!=D+1+D+1)
                    {
                        if(grid[i][j]!='.')
                        {
                            flag=1;
                            break;
                        }

                    }
                    else
                    {
                        if(grid[i][j]!='-')
                        {
                            flag=1;
                            break;
                        }

                    }
                }
            }

        }
        if(flag==1)
        {
            printf("Case %d: Bad\n",cs);
        }
        else
        printf("Case %d: %d\n",cs,D);


    }
    return 0;
}
