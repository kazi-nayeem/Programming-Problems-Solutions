#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

struct data{
    char str[105];
    int q, s;
    bool operator < (const data & t) const
    {
        if(q != t.q) return q < t.q;
        return s < t.s;
    }
};

data arr[105];

int main()
{
    char str[100];
    int len, n, te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d%d", &len, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", arr[i].str);
            arr[i].s = i;
            arr[i].q = 0;
            for(int j = 0; j < len; j++)
                for(int k = j+1; k < len; k++)
                if(arr[i].str[j] > arr[i].str[k])
                    arr[i].q++;
        }
        sort(arr, arr+n);
        for(int i = 0; i < n; i++)
            printf("%s\n", arr[i].str);
        if(te) puts("");
    }
    return 0;
}
