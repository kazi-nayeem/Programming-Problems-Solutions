#include<cstdio>
using namespace std;

int arr[10] = {2,7,2,3,3,4,2,5,1,2};

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", arr[n%10]*arr[(n/10)%10]);
    return 0;
}
