#include<cstdio>
#include<cstring>
using namespace std;

int arr[26];
char str[505];
char res[1000];

int main()
{
    int len, pos;
    while(gets(str))
    {
        if(str[0] == '#') return 0;
        len = strlen(str);
        pos = 0;
        memset(arr, 0, sizeof arr);
        for(int i = 0; i < len; i++)
            arr[str[i]-'a']++;
        for(int i = 0; i < 26; i++)
            if(arr[i]%2 == 1)
            res[pos++] = i+'a';
        if(pos > 1)
        {
            res[pos-1] = '\0';
            puts(res);
        }
    }
    return 0;
}
