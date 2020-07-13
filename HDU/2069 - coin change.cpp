#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int

lli arr[255];

int main()
{
    for(int i = 0, t1 = 0; i <= 100; i++, t1++)
        for(int j = i, t2 = t1; j <= 100 && t2<=250; j++,t2+=5)
            for(int k = j, t3 = t2; k <= 100 && t3<=250; k++,t3+=10)
                for(int l = k,t4 = t3; l <= 100 && t4<=250; l++, t4+=25)
                    for(int m = l,t5 = t4; m <= 100 && t5<=250; m++, t5+=50)
                        arr[t5]++;

    int n;
    while(scanf("%d", &n) == 1)
        printf("%lld\n", arr[n]);
    return 0;
}
