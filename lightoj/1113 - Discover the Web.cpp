#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    stack<string> backwa, forwa;
    int time, test;
    char str[70];

    scanf("%d", &time);
    getchar();

    for(test = 1; test <= time; test++)
    {
        while(!backwa.empty()) backwa.pop();
        while(!forwa.empty()) forwa.pop();

        printf("Case %d:\n", test);
        backwa.push( (string) "http://www.lightoj.com/" );

        while(gets(str))
        {
            if(str[0] == 'V')
            {
                puts(str + 6);
                backwa.push((string) (str+6));

                while(!forwa.empty()) forwa.pop();

                continue;
            }

            if(str[0] == 'B')
            {
                if((int)backwa.size() < 2)
                {
                    puts("Ignored");
                    continue;
                }

                forwa.push(backwa.top());
                backwa.pop();

                cout<<backwa.top()<<endl;

                continue;
            }

            if(str[0] == 'F')
            {
                if(forwa.empty())
                {
                    puts("Ignored");
                    continue;
                }
                cout<<forwa.top()<<endl;

                backwa.push(forwa.top());
                forwa.pop();

                continue;
            }

            if(str[0] == 'Q') break;
        }
    }
    return 0;
}
