#include<stdio.h>
#include<math.h>

int main()
{
    int number[50];
    int n, count;
    int i, j;
    int temp1, temp2, gcd;
    while(scanf("%d", &n) == 1 && (n != 0))
    {
        for(i = 0; i < n; i++)
            scanf("%d", &number[i]);
        for(count = i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
        {
            for(temp1 = number[i], gcd = number[j];(temp1%gcd != 0);gcd = temp2)
            {
                temp2 = temp1%gcd;
                temp1 = gcd;
            }
            if(gcd == 1)
                count++;
        }
        if(count == 0)
            printf("No estimate for this data set.\n");
        else
        {
            printf("%.6lf\n", sqrt((double) 3 * n * (n - 1) /count));
        }
    }
    return 0;
}
