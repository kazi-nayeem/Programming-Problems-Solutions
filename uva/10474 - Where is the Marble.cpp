#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

#define MX 10005

int arr[MX];

int binary(int n, int fi);
int comp(const void *a, const void *b);

int main()
{
    int n, q, fi, te = 1, po;
    while(scanf(" %d %d", &n, &q) == 2)
    {
        if(n == 0 && q == 0) return 0;

        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        qsort(arr, n, sizeof (int), comp);

        printf("CASE# %d:\n", te++);

        for(int i = 0; i < q; i++)
        {
            scanf("%d", &fi);
            po = binary(n-1, fi);
            if(arr[po] == fi)
            {
                for(int j = po-1; arr[j] == arr[po]; j--)
                    po = j;
                printf("%d found at %d\n", fi, po+1);
            }
            else
                printf("%d not found\n", fi);
        }
    }
}

int comp(const void *a, const void *b)
{
    return (*((int *) a)) - (*((int *) b));
}

int binary(int n, int fi)
{
    int beg, en, mid;
    mid = n/2;
    for(beg = 0, en = n; beg <= en;)
    {
        if(arr[mid] == fi) break;
        else if(arr[mid] < fi)
            beg = mid+1;
        else
            en = mid-1;
        mid = (beg+en)/2;
    }
    return mid;
}
