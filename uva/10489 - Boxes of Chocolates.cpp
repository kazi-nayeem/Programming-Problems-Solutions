#include<cstdio>
using namespace std;

int main()
{
    int tim, frien, boxs, total, mo, i, b, temp;
    scanf("%d", &tim);
    while(tim--)
    {
        total = 0;
        scanf("%d %d", &frien, &boxs);
        //for(temp = frien; temp * frien > temp; temp *= frien);

        while(boxs--)
        {
            mo = 1;
            scanf("%d", &i);
            while(i--)
            {
                scanf("%d", &b);
                mo = (mo * b) % frien;
            }

            total += mo;
        }
        printf("%d\n", total);
    }
    return 0;
}
