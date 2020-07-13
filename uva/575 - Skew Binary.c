#include<stdio.h>
#include<string.h>

int main()
{
    long int i, total;
    int len;
    char number[50];
    while(gets(number))
    {
        len = strlen(number);
        if(len == 1 && number[0] == '0') break;
        for( total = 0, i = 1; len > 0; ++i)
        {
            switch(number[--len]){
                case '1':
                        total += (1 << i) - 1;
                        break;
                case '2':
                        total +=  (1 << (i+1)) - 2;
            }
        }
        printf("%ld\n", total);
    }
    return 0;
}
