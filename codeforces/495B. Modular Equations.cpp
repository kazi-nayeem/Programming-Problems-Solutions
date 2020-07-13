#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    vector<int> vc;
    int n, m;
    scanf("%d%d", &n, &m);
    if(n == m)
    {
        printf("infinity\n");
        return 0;
    }
    if(n<m)
    {
        printf("0\n");
        return 0;
    }
    n -= m;
    int root = sqrt(n);
    for(int i = 1; i <= root; i++)
    {
        if(n % i == 0)
        {
            vc.push_back(i);
            if(i*i != n) vc.push_back(n/i);
        }
    }
    int cnt = 0;
    for(int i = 0; i < vc.size(); i++)
        if(vc[i] > m) cnt++;
    printf("%d\n", cnt);
    return 0;
}
