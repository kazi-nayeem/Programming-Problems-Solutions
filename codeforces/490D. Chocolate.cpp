#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

struct data
{
    ll area;
    int a, b, m;
    data() {}
    data(int x, int y, int c)
    {
        a = x;
        b = y;
        m = c;
        area = (ll) a*b;
    }
    bool operator < (const data & p) const
    {
        if(area != p.area)
            return area < p.area;
        return m < p.m;
    }
};

vector<data> vc1, vc2;
map<ll,char> mp;

int Binary_Search(ll fin)
{
    int beg = 0, en = vc1.size()-1;
    int mid = (en+beg)/2;
    while(beg <= en)
    {
        mid = (en+beg)/2;
        if(vc1[mid].area == fin) return mid; ///not in upper or lower
        if(vc1[mid].area < fin)  /// = in upper bound
            beg = mid+1;
        else
            en = mid-1;
    }
    return -1; ///mid in binary/en in lower/beg in upper
}

int main()
{
    int a1, b1, a2, b2;
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
    vc1.push_back(data(a1,b1,0));
    for(int i = 0; i < vc1.size(); i++)
    {
        if(vc1[i].area % 3 == 0)
        {
            if(mp.find((ll)vc1[i].area/3*2) == mp.end())
            {
                mp[(ll)vc1[i].area/3*2] = 9;
                if(vc1[i].a %3 == 0)
                    vc1.push_back(data(vc1[i].a/3*2,vc1[i].b,vc1[i].m+1));
                else
                    vc1.push_back(data(vc1[i].a,vc1[i].b/3*2,vc1[i].m+1));
            }
        }
        if((vc1[i].a & 1) == 0 && (mp.find((ll)vc1[i].area/2) == mp.end()))
        {
            mp[(ll)vc1[i].area/2] = 9;
            vc1.push_back(data(vc1[i].a>>1,vc1[i].b,vc1[i].m+1));
        }
        else if((vc1[i].b & 1) == 0 && (mp.find((ll)vc1[i].area/2) == mp.end()))
        {
            mp[(ll)vc1[i].area/2] = 9;
            vc1.push_back(data(vc1[i].a,vc1[i].b>>1,vc1[i].m+1));
        }
    }
    sort(vc1.begin(),vc1.end());
    for(int i = 1; i < vc1.size(); i++)
    {
        if(vc1[i].area != vc1[i-1].area) continue;
        vc1[i].m = vc1[i-1].m;
        //printf("%d %d %d\n", vc1[i].a, vc1[i].b, vc1[i].m);
    }
    mp.clear();
    vc2.push_back(data(a2,b2,0));
    int pos1 = -1, pos2 = -1, mx = 1000000000;
    //printf("ok\n");
    for(int i = 0; i < vc2.size(); i++)
    {
        int pos = Binary_Search(vc2[i].area);
        if(pos != -1)
        {
            if(vc2[i].m+vc1[pos].m < mx)
            {
                pos1 = pos;
                pos2 = i;
                mx = vc2[i].m+vc1[pos].m;
            }
        }
        if(vc2[i].area % 3 == 0)
        {
            if(mp.find((ll)vc2[i].area/3*2) == mp.end())
            {
                mp[(ll)vc2[i].area/3*2] = 9;
                if(vc2[i].a % 3 == 0)
                    vc2.push_back(data(vc2[i].a/3*2,vc2[i].b,vc2[i].m+1));
                else
                    vc2.push_back(data(vc2[i].a,vc2[i].b/3*2,vc2[i].m+1));
            }
        }
        if((vc2[i].a & 1) == 0 && (mp.find((ll)vc2[i].area/2) == mp.end()))
        {
            mp[(ll)vc2[i].area/2] = 9;
            vc2.push_back(data(vc2[i].a>>1,vc2[i].b,vc2[i].m+1));
        }
        else if((vc2[i].b & 1) == 0 && (mp.find((ll)vc2[i].area/2) == mp.end()))
        {
            mp[(ll)vc2[i].area/2] = 9;
            vc2.push_back(data(vc2[i].a,vc2[i].b>>1,vc2[i].m+1));
        }
    }
    if(pos1 == -1)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n%d %d\n%d %d\n", mx, vc1[pos1].a, vc1[pos1].b, vc2[pos2].a, vc2[pos2].b);
    return 0;
}

