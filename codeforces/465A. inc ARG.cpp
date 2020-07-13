#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[105];
    int len;
    scanf("%d", &len);
    getchar();
    gets(str);
    int total = 0;
    for(int i = 0; i < len; i++, total++)
    {
        if(str[i] == '0')
        {
            total++;
            break;
        }
    }
    printf("%d\n", total);
    return 0;
}
