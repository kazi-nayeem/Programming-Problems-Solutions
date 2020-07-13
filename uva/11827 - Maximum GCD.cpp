#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>

using namespace std;
int fgcd(int n, int m);

int main()
{
    vector<int> number;
    int test, maxi, gcd;
    char str[1000];
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        maxi = 0;
        number.clear();
        gets(str);
        stringstream ss(str);
        int num;
        while(ss>>num)
            number.push_back(num);
        int siz = number.size();
        for(int i = 0; i < siz; i++)
        {
            for(int j = i + 1; j < siz; j++)
            {
                gcd = fgcd(number[i], number[j]);
                if(maxi < gcd)
                    maxi = gcd;
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
int fgcd(int n, int m)
{
    if(m == 0)
        return n;
    if(n % m == 0)
        return m;
    return fgcd(m, n % m);
}
