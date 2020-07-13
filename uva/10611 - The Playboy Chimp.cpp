#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

#define MX 50005

int arr[MX];
int girl;

int binary(int fi);

int main()
{
    int qu, fi, low, up, pos;
    while(scanf("%d", &girl) == 1)
    {
        for(int i = 0; i < girl; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &qu);
        for(int i = 0; i < qu; i++)
        {
            scanf("%d", &fi);
            pos = binary(fi);

            if(arr[pos] == fi)
            {
                for(low = pos - 1; arr[low] == fi; low--);
                for(up = pos+1; arr[up] == fi; up++);
            }
            else if(arr[pos] < fi)
                low = pos, up = pos + 1;
            else
                low = pos - 1, up = pos;

            if(low >= 0)
                printf("%d ", arr[low]);
            else
                printf("X ");
            if(up < girl)
                printf("%d\n", arr[up]);
            else
                printf("X\n");
        }
    }
    return 0;
}

int binary(int fi)
{
    int beg = 0, en = girl -1;
    int mid = (en)/2;
    for(; beg <= en; mid = (beg+en)/2)
    {
        if(arr[mid] == fi) return mid;
        if(arr[mid] > fi)
            en = mid-1;
        else
            beg = mid+1;
    }
    return mid;
}
