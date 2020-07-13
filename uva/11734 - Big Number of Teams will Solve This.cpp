#include<cstdio>
#include<cstring>
using namespace std;

#define MX 25

int main()
{
    char str1[MX], str2[MX], ch1, ch2;
    int ti, te, len;
    scanf("%d", &ti);
    getchar();

    for(te = 1; te <= ti; te++)
    {
        gets(str1);
        gets(str2);

        if(strcmp(str1, str2) == 0)
        {
            printf("Case %d: Yes\n", te);
            continue;
        }

        int i = 0;
        len = strlen(str1);
        for(int j = 0; j < len; j++)
        {
            if(str1[j] == ' ') continue;
            str1[i++] = str1[j];
        }
        str1[i] = '\0';

        if(strcmp(str1, str2) == 0)
            printf("Case %d: Output Format Error\n", te);
        else
            printf("Case %d: Wrong Answer\n", te);
    }
    return 0;
}
