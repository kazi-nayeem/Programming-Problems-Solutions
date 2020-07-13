#include<cstdio>
using namespace std;

#define MX 1005

int number[MX];

int main()
{
    int n, temp;
    while(scanf("%d", &n) == 1)
    {
        int maxi = 0;
        for(int i=0; i < n; i++)
        {
            scanf("%d", &temp);
            number[temp]++;
            if(temp > maxi)
            maxi = temp;
        }
        int high = 0, tower = 0;
        for(int i = 0; i <= maxi; i++)
        {
            if(number[i])
            {
                tower++;
                if(number[i] > high)
                    high = number[i];
            }
            number[i] = 0;
        }
        printf("%d %d\n", high, tower);
    }
    return 0;
}
