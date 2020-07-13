#include<cstdio>
using namespace std;

int main()
{
    int a, b, te, c;
    scanf("%d", &te);
  
    for(int i = 1; i <= te; i++)
    {

        scanf("%d %d", &a, &b);
        c = a+b;
        printf("Case %d: %d\n", i, c);
    }
    return 0;
}
