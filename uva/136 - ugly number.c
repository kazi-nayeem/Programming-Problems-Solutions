#include<stdio.h>

int main()
{
    unsigned long long int i, j;
    int ugly;
    for(i = 6, ugly = 5; ugly < 1500 ; i++)
    {
        for(j = i; !(j % 2) ; j/=2);
        for(;!(j % 3); j /= 3);
        for(;!(j % 5); j /= 5);
        if(j == 1) ugly++;
    }
    printf("The 1500\'th ugly number is %d", --i);
}
