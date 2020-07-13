#include<stdio.h>
#include<string.h>
#include<math.h>

short int prime(int n);

int main()
{
    short int l, i, s;
    char word[21];
    while(scanf("%20s", word) == 1)
    {
        l = strlen(word);
        if(l == 0) break;
        for(s = 0, i = 0; i < l ; ++i)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
                s += word[i] - 'a' + 1;
            else if(word[i] >= 'A' && word[i] <= 'Z')
                s += word[i] - 'A' + 27;
        }
        if(prime(s))
        printf("It is a prime word.\n");
        else
        printf("It is not a prime word.\n");
    }
    return 0;
}

short int prime(int n)
{
    short int i, r;
    r = sqrt(n);
    for(i = 2; i <= r ; ++i)
        if(n % i == 0)
        return 0;
    return 1;
}
