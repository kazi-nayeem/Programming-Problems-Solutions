#include<stdio.h>
#include<string.h>

#define MAX 1000000

int main()
{
    char string[MAX];
    long int count, len;
    long int three, eleven;
    long int temp;
    int fthree, ffive, feleven, flag, fla, j = 0;
    while(gets(string))
    {
        if(j == 1)
            printf("\n");
        j = 1;
        len = strlen(string);
        if(len == 0) break;
        flag = 1;
        three = eleven = fthree = ffive = feleven = 0;
        if(len > 6)
            sscanf(string + len - 5, "%d", &temp);
        else
            sscanf(string, "%d", &temp);
        if(temp % 400 == 0)
        {
            printf("This is leap year.\n");
            flag = 0;
            fla = 1;
        }
        else if(temp % 100 == 0)
            fla = 0;
        else if(temp % 4 == 0)
        {
            printf("This is leap year.\n");
            flag = 0;
            fla = 1;
        }
        else
            fla = 0;
        if(string[len - 1] == '0' || string[len - 1] == '5')
            ffive = 1;
        for(count = 0; count < len ; count += 2)
        {
            temp = (int) string[count] - 48;
            eleven += temp;
            three += temp;
        }
        for(count = 1; count < len ; count += 2)
        {
            temp = (int) string[count] - 48;
            eleven -= temp;
            three += temp;
        }
        if(eleven % 11 == 0)
            feleven = 1;
        if(three % 3 == 0)
            fthree = 1;
        if(fthree && ffive)
        {
            printf("This is huluculu festival year.\n");
            flag = 0;
        }
        if(ffive && feleven && fla)
        {
            printf("This is bulukulu festival year.\n");
            flag = 0;
        }
        if(flag)
            printf("This is an ordinary year.\n");
    }
    return 0;
}
