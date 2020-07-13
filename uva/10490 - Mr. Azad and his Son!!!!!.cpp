#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


#define MX 46355
#define MXP 4794
#define ll long long int

char str[100][100] = { "",
"Perfect: 1!",
"Perfect: 6!",
"Perfect: 28!",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 496!",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 8128!",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is prime. But, NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 33550336!",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 8589869056!",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 137438691328!",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is prime. But, NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Given number is prime. But, NO perfect number is available.",
"Given number is NOT prime! NO perfect number is available.",
"Perfect: 2305843008139952128!"
};

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        printf("%s\n", str[n]);
    }
}
