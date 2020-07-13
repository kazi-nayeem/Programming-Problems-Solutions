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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;


string str[100];

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            cin>>str[i];
            //cout<<str[i]<<endl;
        }
        //cout<<str[0].substr(1,2)<<endl;
        int len = str[0].size();
        string ans = "";
        for(int i = 0; i < len; i++)
            for(int j = i+1; j <= len; j++)
            {
                bool flag = true;
                for(int k = 1; k < n; k++)
                {
                    bool f = false;
                    for(int l = 0; l+j-i <= str[k].size(); l++)
                    {
                        if(str[0].substr(i,j-i) == (str[k].substr(l,j-i)))
                        {
                            f = true;
                            break;
                        }
                    }
                    if(!f)
                    {
                        flag = false;
                    }
                }
                if(flag)
                {
                    //puts("ok");
                    //cout<<str[0].substr(i,j)<<endl;
                    if(str[0].substr(i,j-i).size() > ans.size())
                    {
                        ans = str[0].substr(i,j-i);
                    }
                    if(str[0].substr(i,j-i).size() == ans.size() && str[0].substr(i,j-i) < ans)
                    {
                        ans = str[0].substr(i,j-i);
                    }
                }
            }
        cout<<ans<<endl;

    }

    return 0;
}


