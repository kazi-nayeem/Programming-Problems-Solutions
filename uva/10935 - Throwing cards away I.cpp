#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    queue<int> card;
    int i, n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        if(n > 1)
        {
            for(i = 1; i <= n; i++)
                card.push(i);
            printf("Discarded cards: %d", card.front());
            card.pop();
            card.push(card.front());
            card.pop();
            n--;
            for(i  = 1; i < n ; i++)
            {
                printf(", %d", card.front());
                card.pop();
                card.push(card.front());
                card.pop();
            }
            printf("\nRemaining card: %d\n", card.front());
            card.pop();
        }
        else
            printf("Discarded cards:\nRemaining card: 1\n");
    }
    return 0;
}
