#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

char str[100005];
vector<int> vc;

int main()
{
    gets(str);
    int len = strlen(str);
    int f = 0, h = 0, c = 0;
    int flag = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
        {
            /*if(h > 0)
            {
                if(h > f) flag = 1;
                else
                {
                    for(int i = 1; i < h; i++)
                        vc.push_back(1);
                    vc.push_back(f-h+1);
                }
                h = f = 0;
            }*/
            f++;
            c++;
        }
        else if(str[i] == '#')
        {
            if(f <= h) flag = 1;
            h++;
            c = 0;
        }
        else
        {
            if(f == 0) flag = 1;
            f--;
            if(c > 0)
                c--;
        }
        if(flag) break;
    }
    if(h > 0)
    {
        if(h > f) flag = 1;
        else
        {
            for(int i = 1; i < h; i++)
                vc.push_back(1);
            vc.push_back(f-h+1);
        }
        h = f = 0;
    }
    if(f || c) flag = 1;
    if(flag)
    {
        vc.clear();
        vc.push_back(-1);
    }
    for(int i = 0; i < vc.size(); i++)
        printf("%d\n", vc[i]);
    return 0;
}
