#include<cstdio>
#include<cstring>
using namespace std;

typedef long long int ll;

char month[12][14] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int main()
{
    char str[15];
    int te, ti, d1, d2, m1, m2;
    ll y1, y2, res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%s%d,%lld", str, &d1, &y1);
        for(int i = 0; i < 12; i++)
            if(strcmp(str,month[i]) == 0)
        {
            m1 = i+1;
            break;
        }
        scanf("%s%d,%lld", str, &d2, &y2);
        for(int i = 0; i < 12; i++)
            if(strcmp(str,month[i]) == 0)
        {
            m2 = i+1;
            break;
        }
        res = 0;
        if((y1%400 == 0) || (y1%4 == 0 && y1 %100 != 0))
        {
            if(m1 <= 2) res++;
        }
        if((y2%400 == 0) || (y2%4 == 0 && y2 %100 != 0))
        {
            if(m2 < 2) res--;
            else if(m2 == 2 && d2 <= 28) res--;
        }
        res += -y1/4+y2/4+y1/100-y2/100-y1/400+y2/400;
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
