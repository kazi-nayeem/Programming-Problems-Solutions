#include<cstdio>
#include<cstring>
using namespace std;

int arr[10];
int div[10] = {8,4,6,2,9,3,5,7};
int main()
{
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        memset(arr,0,sizeof arr);
        for(int i = 0; i < 8; i++)
        {
            if(n % div[i] == 0)
                {
                    arr[div[i]] = 1;
                    n /= div[i];
                }
        }
        if(n>1) printf("-1\n");
        else
        {
            for(int i = 2; i <= 9; i++)
                if(arr[i])
                printf("%d", i);
            putchar('\n');

        }
    }
    return 0;
}
