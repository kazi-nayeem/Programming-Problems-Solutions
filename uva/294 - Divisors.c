#include<stdio.h>
#include<math.h>

#define LI long int

int main()
{
    int arr[10005];
    LI low, high;
    LI i, j, k;
    LI maxi;
    double rootd;
    LI rooti[10005];
    int time;
    scanf("%d", &time);
    while(time--)
    {
        scanf("%ld %ld", &low, &high);
        for(i = low; i <= high; i++)
        {
            rootd = (double) sqrt(i);
            rooti[i-low] = (LI) rootd;
            if(rooti[i-low] == rootd)
                arr[i-low] = 1;
            else
                arr[i-low] = 2;
        }
        maxi = high - low;
        for(i = 2; i <= rooti[maxi]; i++)
        {
            for(j = low; j <= high; j++)
            {
                if(i <= rooti[j - low])
                {
                    if(j % i == 0)
                        arr[j - low] += 2;
                }
            }
        }
        k = high - low;
        for(maxi = 0,i = 0; i <= k; i++)
        {
            if(arr[maxi] < arr[i])
                maxi = i;
        }
        printf("Between %ld and %ld, %ld has a maximum of %d divisors.\n", low, high, maxi + low, arr[maxi]);
    }
    return 0;
}
