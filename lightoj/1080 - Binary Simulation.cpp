#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100040

char tree[MX*3];
char str[MX];

void update(int node, int b, int e, int i, int j);
char query(int node, int b, int e, int i, char cary);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, n, q, x, y;
    char ch;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf(" %s%d", str, &q);
        printf("Case %d:\n", te);
        //printf("%s\n", str);
        n = strlen(str);
        memset(tree, 0, sizeof tree);
        for(int i = 0; i < q; i++)
        {
            scanf(" %c%d", &ch, &x);
            if(ch == 'Q')
            {
                //printf("%c %d\n", ch, x);
                x--;
                printf("%c\n", query(1,0,n-1,x,(char)0));
            }
            else
            {
                scanf("%d", &y);
                x--, y--;
                update(1,0,n-1,x,y);
                //printf("%c %d %d\n", ch, x, y);
            }
        }
    }
    return 0;
}

void update(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return;
    if(i <= b && j >= e)
    {
        tree[node]=(1^tree[node])&1;
        return;
    }
    int mid = (b+e)/2;
    update(node*2, b, mid, i, j);
    update(node*2+1, mid+1, e, i, j);
    return;
}
char query(int node, int b, int e, int i, char cary)
{
    if(b > i || e < i) return 0;
    if(b == e)
    {
        if(b == i)
        {
            cary=(cary^tree[node])&1;
            char ch = str[i];
            if(cary == 1)
            {
                if(ch == '0') return '1';
                return '0';
            }
            return ch;
        }
        return 0;
    }
    int mid = (b+e)/2;
    char ch1 = query(node*2,b,mid,i,(cary^tree[node])&1);
    char ch2 = query(node*2+1,mid+1,e,i,(cary^tree[node])&1);
    return ch2|ch1;
}
