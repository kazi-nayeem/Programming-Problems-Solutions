#include<cstdio>
#include<iostream>
using namespace std;

int arr[200], temp[200], mov;

void mergesort(int left, int right);
void mergi(int left,int mid, int right);

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        mov = 0;
        for(int i = 1; i <=n; i++)
            scanf("%d", arr+i);
        mergesort(1,n);
        //for(int i = 1; i <= n; i++)
        //    printf("%d\n", arr[i]);
        //puts("\n");
        printf("%d\n", mov);
    }
    return 0;
}

void mergesort(int left, int right)
{
    int mid = (left+right)/2;
    if(left < right)
    {
        mergesort(left,mid);
        mergesort(mid+1,right);
        mergi(left,mid,right);
    }
    return;
}
void mergi(int left,int mid, int right)
{
    int pos = 0, lpos = left, rpos = mid+1;
    while(lpos<=mid && rpos <= right)
    {
        if(arr[lpos] < arr[rpos])
            temp[pos++] = arr[lpos++];
        else
            temp[pos++] = arr[rpos++], mov++;
    }
    while(lpos <= mid) temp[pos++] = arr[lpos++];
    while(rpos <= right) temp[pos++] = arr[rpos++];
    for(int i=0;i<pos;i++)
        arr[left+i] = temp[i];
    return;
}

