#include<cstdio>
using namespace std;

int main()
{
    int time, test, m, n;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &m, &n);
        if(m > n)
            m ^= n ^= m ^= n;
        if(m == 1)
            printf("Case %d: %d\n", test, n);
        else if(m == 2)
        {
            int total = (n / 4) * 4;
            n %= 4;
            if(n == 1)
                total += 2;
            else if(n)
                total += 4;
            printf("Case %d: %d\n", test, total);
        }
        else
            printf("Case %d: %d\n", test, ((m*n)+1)/2);
    }
    return 0;
}
