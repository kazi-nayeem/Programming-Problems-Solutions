#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<assert.h>
#include<time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<25)
#define mp make_pair
#define fs first
#define sc second
#define __ std::ios_base::sync_with_stdio (false)

template<class T1> void deb(T1 e1) {cout << e1 << "\n";}
template<class T1, class T2> void deb(T1 e1, T2 e2) {cout << e1 << " " << e2 << "\n";}
template<class T1, class T2, class T3> void deb(T1 e1, T2 e2, T3 e3) {cout << e1 << " " << e2 << " " << e3 << "\n";}
template<class T1, class T2, class T3, class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4) {cout << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";}
template<class T1, class T2, class T3, class T4, class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";}
template<class T1, class T2, class T3, class T4, class T5, class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << "\n";}

double dp[55][55][2550];
int save[55][55][2550];
int row, col, now = 1;

double rec(int tkr, int tkc, int tk)
{
    if(tkr == row && tkc == col) return 1.0;
    if(tk == row*col)
    {
        return 0.0;
    }
    if(tkr > row || tkc > col) return 0.0;
    double & res = dp[tkr][tkc][tk];
    if(save[tkr][tkc][tk] == now) return res;
    save[tkr][tkc][tk] = now;
    res = 0.0;
    if((tkc*row-tkc*tkr)>0)
    res += (double)(tkc*row-tkc*tkr)*(rec(tkr+1,tkc,tk+1)+1);
    if((tkr*col-tkc*tkr)>0)
    res += (double)(tkr*col-tkc*tkr)*(rec(tkr,tkc+1,tk+1)+1);
    if((tkc*tkr-tk)>0)
    res += (double)(tkc*tkr-tk)*(rec(tkr,tkc,tk+1)+1);
    if((row*col-tkc*row-tkr*col+tkc*tkr)>0)
    res += (double)(row*col-tkc*row-tkr*col+tkc*tkr)*(rec(tkr+1,tkc+1,tk+1)+1);
    res /= (row*col-tk);
    return res;
}



int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &row, &col);
        now++;
        printf("%.12lf\n", rec(0, 0, 0)-1.0);
    }
    return 0;
}
