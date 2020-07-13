#include <cstdio>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;
typedef pair<short,short> pii;

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/

#define MX  100005
#define inf 100000000


char mat[(1<<12)][(1<<11)];

char check(char mask, int pos) {
    return (mask>>(7-pos))&1;
}

char setBit(char mask, int pos) {
    return mask^(1<<(7-pos));
}

bool isone(int x, int y) {
    return check(mat[x][y>>3],y&7);
}

void setVisited(int x, int y) {
    mat[x][y>>3] = setBit(mat[x][y>>3],y&7);
}

int cnt;
int n, m;
queue<pii> qu;

void dfs(int x, int y) {
    //deb(x,y);
    if(x<0 || y < 0 || x >= n || y >= m) return;
    //deb("--",x,y);
    if(isone(x,y) == 0) return;
    setVisited(x,y);
    qu.push(make_pair(x,y));
    cnt = 0;
    while(!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        cnt++;
        for(int i = 0; i < 4; i++) {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx<0 || ty < 0 || tx >= n || ty >= m) continue;
            //deb("--",x,y);
            if(isone(tx,ty) == 0) continue;
            setVisited(tx,ty);
            qu.push(make_pair(tx,ty));
        }
    }
}

char str[MX];

int main() {
//    ios_base::sync_with_stdio(0);
//    freopen("00.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        for(int j = 0; j < (m>>2); j++) {
            int v;
            if(str[j]>='0' && str[j] <= '9')
                v = str[j]-'0';
            else
                v = str[j]-'A'+10;
            if(j%2 == 0)
                v = (v<<4);
            //deb(v);
            mat[i][j/2] = mat[i][j/2]|v;
            //deb((int) mat[i][j/2]);
        }
    }
//    for(int i = 0; i < n; i++, puts(""))
//        for(int j = 0; j < m; j++) {
//            printf("%d", isone(i,j));
//        }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cnt = 0;
            dfs(i,j);
            ans += cnt != 0;
        }
    printf("%d\n", ans);
    return 0;
}






























