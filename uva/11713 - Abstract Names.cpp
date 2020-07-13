#include<cstdio>
#include<cstring>
using namespace std;

#define MX 25

int main()
{
    char str1[MX], str2[MX], ch1, ch2;
    int ti, len, flag;
    scanf("%d", &ti);
    getchar();

    while(ti--)
    {
        gets(str1);
        gets(str2);
        len = strlen(str1);
        if(len != strlen(str2))
        {
            printf("No\n");
            continue;
        }
        flag = 1;
        for(int i = 0; i < len; i++)
        {
            if(str1[i] == str2[i]) continue;
            ch1 = str1[i];
            if(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u')
            {
                ch2 = str2[i];
                if(!(ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u'))
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
