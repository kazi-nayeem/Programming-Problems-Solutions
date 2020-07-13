#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<set>
using namespace std;

char str[100], temp[100];
set<string> mp;

int pesky( void );
bool check(int i,int j);

int main()
{
    while(gets(str))
    {
        printf("The string '%s' contains %d palindromes.\n", str, pesky());
    }
    return 0;
}

int pesky( void )
{
    mp.clear();
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        for(int j = i; j < len; j++)
    {
        if(check(i,j))
        {
            int l = 0;
            for(int k = i; k <= j; k++, l++)
                temp[l] = str[k];
            temp[l] = '\0';
            mp.insert((string)temp);
        }
    }
    return (int) mp.size();
}

bool check(int i,int j)
{
    for(;i < j;i++,j--)
        if(str[i] != str[j])
            return false;
    return true;
}
