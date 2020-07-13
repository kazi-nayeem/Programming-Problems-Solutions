#include<cstdio>
#include<math.h>
using namespace std;

#define MAX 51

int arr[MAX];
int ans[MAX];

int main()
{
    int n = 0;

    for(int i = 1; n < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(arr[j] == 0)
            {
                ans[j] = i - 1;
                arr[j] = i;
                n++;
                break;
            }

            int root = ceil(sqrt(arr[j]+i));

            if(root * root == arr[j]+i)
            {
                arr[j] = i;
                break;
            }
        }
    }
    scanf("%d", &n);
    while(n--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
    return 0;
}
