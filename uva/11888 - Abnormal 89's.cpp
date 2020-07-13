#include<cstdio>
#include<cstring>
using namespace std;

char str[200002];

bool check(int i, int j);

int main()
{
    int len, ti;
    bool ali;
    scanf("%d", &ti);
    getchar();
    while(ti--)
    {
        gets(str);
        len = strlen(str);
        ali = false;
        for(int i = 0; i + 1 < len; i++)
        {
            if(check(0,i))
                if(check(i+1,len-1))
            {
                ali = true;
                break;
            }
        }
        if(ali)
            printf("alindrome\n");
        else if(check(0,len-1))
            printf("palindrome\n");
        else
            printf("simple\n");
    }
    return 0;
}

bool check(int i, int j)
{
    for(;i < j;i++,j--)
        if(str[i] != str[j])
        return false;
    return true;
}
