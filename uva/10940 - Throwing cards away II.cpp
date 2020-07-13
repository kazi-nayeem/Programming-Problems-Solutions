#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int total;
    queue<int> card;
    int i, n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        for(i = 1; i <= n; i++)
            card.push(i);
        n--;
        total = 0;
        while(n--)
        {
            card.pop();
            total++;
            card.push(card.front());
            card.pop();
            total++;
        }
        printf("%d total %d\n", card.front(), total);
        card.pop();
    }
    return 0;
}
