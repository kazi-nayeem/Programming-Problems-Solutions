#include<stdio.h>
#include<math.h>

#define MAX 100000002LL
#define LLI long long int
LLI mode[MAX];

void funct(void);
void modul(void);

int main()
{
    funct();
    LLI n;
    int ti, te;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", te, mode[n]);
    }
    return 0;
}

void funct(void)
{
    LLI i, j, k, root = (LLI) sqrt(MAX);
    mode[1] = 1;
    for( i = 6; i < MAX; i+=2)
        mode[i] = 1;
    for(i = 2; i < MAX; i <<=1)
        mode[i] = 2;
    for(i = 3; i <= root; i+=2)
    {
        if(mode[i] == 0)
        {
            k = i << 1;
            for(j = i*i; j < MAX; j += k)
                mode[j] = 1;
            for(j = i; j < MAX; j *= i)
                mode[j] = i;
        }
    }
    modul();
    return;
}

void modul(void)
{
    unsigned LLI total = 1,mo;
    mo = (unsigned LLI) 4294967296llu;
    LLI i;
    for(i = 1; i < MAX; i++)
    {
        if(mode[i]>1)
            total *= mode[i];
        else if(mode[i] == 0)
            total *= i;

        total %= mo;
        mode[i] = total % mo;
    }
    return;
}
