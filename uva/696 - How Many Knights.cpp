#include<cstdio>
using namespace std;

int main()
{
    int m, n, row, col;

    while(scanf("%d %d", &m, &n) == 2)
    {
        if(m == 0 && n == 0) return 0;
        row = m, col = n;
        if(m > n)
            m ^= n ^= m ^= n;

        if(m == 1)
            printf("%d knights may be placed on a %d row %d column board.\n",  n, row, col);
        else if(m == 2)
        {
            int total = (n / 4) * 4;
            n %= 4;
            if(n == 1)
                total += 2;
            else if(n)
                total += 4;
            printf("%d knights may be placed on a %d row %d column board.\n",  total, row, col);
        }
        else
            printf("%d knights may be placed on a %d row %d column board.\n",  ((m*n)+1)/2, row, col);
    }
    return 0;
}
