#include<stdio.h>
#include<string.h>

void reves(int n);

int main()
{
    unsigned int t, n;
    scanf("%u ", &n);
    for(t = 0; t < 101 && n != 0 ; ++t)
    {
        reves(n);
        scanf("%u", &n);
    }
    return 0;
}

void reves(int n)
{
    char arr[100] = "", rarr[100] = "";
    int i, j, k, l;
    gets(arr);
    k = strlen(arr);
    for(i = 0, l = 1; i < k;  l++)
    {
        j = i+n-1;
        for(;i < n*l; i++, j--)
        rarr[j] = arr[i];
    }
    printf("%s\n", rarr);
    return;
}

