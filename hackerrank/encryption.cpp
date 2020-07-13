#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char str[10000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    gets(str);
    int len = strlen(str);
    int row = sqrt(len);
    int col = ceil(sqrt(len));
    for(int i = 0; i < col; i++)
    {
        for(int j = i; j < len; j+=col)
            putchar(str[j]);
        putchar(' ');
    }
    return 0;
}
