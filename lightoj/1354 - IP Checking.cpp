#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int decimal[4], binary[4], len[4];
    char str[4][35];
    int time, test;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d.%d.%d.%d", &decimal[0], &decimal[1], &decimal[2], &decimal[3]);
        getchar();
        scanf("%[^.].%[^.].%[^.].%[^\n]", str[0], str[1], str[2], str[3]);

        for(int i = 0; i < 4; i++)
        {
            len[i] = strlen(str[i]);
            binary[i] = 0;
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < len[i]; j++)
            {
                if(str[i][j] == '1')
                {
                    binary[i] ^= (1 << (len[i] - j - 1));
                }
            }
        }

        if(decimal[0]==binary[0] && decimal[1]==binary[1] && decimal[2]==binary[2] && decimal[3]==binary[3])
            printf("Case %d: Yes\n", test);
        else
            printf("Case %d: No\n", test);
    }
    return 0;
}
