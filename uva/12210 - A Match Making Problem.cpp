#include<cstdio>
using namespace std;

int arr[10005];

int main()
{
    int s, b, te, ti = 1;
    while(scanf("%d %d", &b, &s) == 2)
    {
        if(b == 0 && s == 0) return 0;
        for(int i = 0; i < b; i++)
            scanf("%d", arr+i);
        for(int i = 0; i < s; i++)
            scanf("%d", &te);
        if(s >= b)
            printf("Case %d: 0\n", ti++);
        else
        {
            int mi = arr[0];
            for(int i = 1; i < b; i++)
                if(arr[i] < mi) mi = arr[i];
            printf("Case %d: %d %d\n", ti++, b - s, mi);
        }
    }
    return 0;
}
