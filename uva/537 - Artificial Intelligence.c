#include<stdio.h>
#include<string.h>

#define MAX 105

#define addprefix(m, ch)  if(ch == 'm') \
                                        m /= 1000; \
                                    else if(ch == 'k') \
                                        m *= 1000; \
                                    else if(ch == 'M') \
                                        m *= 1000000;


int main()
{
    float voltage, power, current;
    int fvoltage, fpower, fcurrent;
    int time, problem;
    char prefix;
    char sentence[MAX];
    int len, count;
    scanf("%d", &time);
    getchar();
    for(problem = 0; problem < time;)
    {
        gets(sentence);
        fvoltage = fpower = fcurrent = 0;
        len = strlen(sentence);
        for(count = 0; count < len; ++count)
        {
            if(sentence[count] == 'P')
            {
                if(sentence[count+1] == '=')
                {
                    sscanf(sentence + count + 2, "%f%ch", &power, &prefix);
                    addprefix(power , prefix);
                    fpower = 1;
                    count += 3;
                }
            }
            else if(sentence[count] == 'U')
            {
                if(sentence[count+1] == '=')
                {
                    sscanf(sentence + count + 2, "%f%ch", &voltage, &prefix);
                    addprefix(voltage , prefix);
                    fvoltage = 1;
                    count += 3;
                }
            }
            else if(sentence[count] == 'I')
            {
                if(sentence[count+1] == '=')
                {
                    sscanf(sentence + count + 2,"%f%ch", &current, &prefix);
                    addprefix(current , prefix);
                    fcurrent = 1;
                    count += 3;
                }
            }
        }
        if(fvoltage == 1 && fcurrent == 1)
            printf("Problem #%d\nP=%.2fW\n\n", ++problem, voltage * current);
        else if(fpower == 1 && fvoltage == 1)
            printf("Problem #%d\nI=%.2fA\n\n", ++problem, power / voltage);
        else if(fpower && fcurrent)
            printf("Problem #%d\nU=%.2fV\n\n", ++problem, power / current);
    }
    return 0;
}
