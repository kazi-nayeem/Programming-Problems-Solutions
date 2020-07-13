#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

int arr[20];
vector<int> vc;
map<int,bool> mp;

int main()
{
    int n, te = 1, ti, co;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d%d", &co, &n);
        vc.clear();
        mp.clear();
        mp[0] = true;
        vc.push_back(0);
        int gc = n;
        for(int i = 0; i < co; i++)
        {
            scanf("%d", &arr[i]);
            gc = __gcd(gc,arr[i]);
        }
        bool flag = false;
        for(int i = 0; i < co; i++)
        {
            if(flag) break;
            int sz = vc.size();
            for(int j = 0; j < sz; j++)
            {
                int tem = vc[j]+arr[i];
                if((mp.find(tem) == mp.end()) && (tem <= n))
                {
                    mp[tem] = true;
                    vc.push_back(tem);
                }
                tem = vc[j]+(arr[i]<<1);
                if((mp.find(tem) == mp.end()) && (tem <= n))
                {
                    mp[tem] = true;
                    vc.push_back(tem);
                }
                if(mp.find(n) != mp.end())
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            printf("Case %d: Yes\n", te++);
        else
            printf("Case %d: No\n", te++);
    }
    return 0;
}
