#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

char str[1000];
int len;
int arr[1000];

int main()
{
    scanf("%d %s", &len, str);
    for(int i = 0; i < len; i++)
        arr[tolower(str[i])-'a']++;
    for(int i = 0; i < 26; i++)
        if(arr[i] == 0)
    {
        printf("NO\n");
        return 0;
    }
    puts("YES");
    return 0;
}
