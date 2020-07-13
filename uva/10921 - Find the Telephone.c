#include<stdio.h>
#include<string.h>

int main()
{
    char str[35];
    int len, count;
    while(gets(str))
    {
        len = strlen(str);
        for(count = 0; count < len; ++count)
        {
            if(str[count] >= 'A' && str[count]<='Z')
            switch(str[count])
            {
                case 'A':
                case 'B':
                case 'C':
                            str[count] = '2';
                            break;
                case 'D':
                case 'E':
                case 'F':
                            str[count] = '3';
                            break;
                case 'G':
                case 'H':
                case 'I':
                            str[count] = '4';
                            break;
                case 'J':
                case 'K':
                case 'L':
                            str[count] = '5';
                            break;
                case 'M':
                case 'N':
                case 'O':
                            str[count] = '6';
                            break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                            str[count] = '7';
                            break;
                case 'T':
                case 'U':
                case 'V':
                            str[count] = '8';
                            break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                            str[count] = '9';
            }
        }
        puts(str);
    }
    return 0;
}

