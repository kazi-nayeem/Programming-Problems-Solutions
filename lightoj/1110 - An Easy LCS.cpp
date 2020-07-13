#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

typedef pair<int,string> pis;

char str1[105], str2[105];
pis dp[101][101];
int len1, len2;

pis func(int i, int j);

int main()
{
    int te , ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%s%s", str1, str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                dp[i][j] = make_pair(-1,(string) "");
        pis result = func(len1-1, len2-1);
        printf("Case %d: ", te);
        if(result.first == 0)
            puts(":(");
        else
            puts(result.second.c_str());
    }
    return 0;
}

pis func(int i, int j)
{
    if(i < 0 || j < 0) return make_pair(0, (string) "");
    pis & res = dp[i][j];
    if(res.first != -1) return res;
    pis ret1 = make_pair(0, (string) ""), ret2 = make_pair(0, (string) "");
    if(str1[i] == str2[j])
    {
        char st[3];
        st[0] = str1[i];
        st[1] = '\0';
        ret1 = func(i-1,j-1);
        return res = make_pair(ret1.first+1,ret1.second+(string) st);
    }
    ret1 = func(i-1, j);
    ret2 = func(i, j-1);
    if(ret1.first == ret2.first)
    {
        if(ret1.second < ret2.second) return res = ret1;
        else return res = ret2;
    }
    if(ret1.first > ret2.first) return res = ret1;
    return res = ret2;
}
