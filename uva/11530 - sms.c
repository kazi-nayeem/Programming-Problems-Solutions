#include<stdio.h>
#include<string.h>

int main()
{
    int len, test, count, t, press;
    char arr[110];
    scanf(" %d", &t);
    getchar();
    for(test = 0; test < t ;)
    {
        gets(arr);
        len = strlen(arr);
        for(press = 0, count = 0; count < len ; ++count)
        {
            switch(arr[count])
            {
                case 'a':
                case 'd':
                case 'g':
                case 'j':
                case 'm':
                case 'p':
                case 't':
                case 'w':
                case ' ':
                            press++;
                            break;
                case 'b':
                case 'e':
                case 'h':
                case 'k':
                case 'n':
                case 'q':
                case 'u':
                case 'x':
                            press += 2;
                            break;
                case 's':
                case 'z':
                            press += 4;
                            break;
                default:
                            press += 3;
            }
        }
        printf("Case #%d: %d\n", ++test, press);
    }
    return 0;
}
