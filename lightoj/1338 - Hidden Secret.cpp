#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int arr[26];

int main()
{
    char ch, str[105];
    int te, ti, len;
    scanf("%d", &ti);
    getchar();
    for(te = 1; te <= ti; te++)
    {
        gets(str);
        memset(arr, 0, sizeof arr);
        len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ') continue;
            ch = tolower(str[i]);
            arr[ch-'a']++;
        }
        gets(str);
        len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ') continue;
            ch = tolower(str[i]);
            arr[ch-'a']--;
        }
        int flag = 1;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] != 0)
            {
                flag = 0;
                break;
            }
        }
        printf("Case %d: %s\n", te, (flag)? "Yes":"No");
    }
    return 0;
}
