#include<stdio.h>

#define MX 1002

/*double dp[MX][MX];

double func(int t, int d) {
    if(t == 0) return 1.0;
    if(t < 0 || d < 0) return 0.0;
    double & res = dp[t][d];
    if(res > -0.5) return res;
    res = 0.0;
    int tot = (t+d)*(t+d+1)/2;
    double tem = (t*d*func(t,d-1)/tot) + (t*(t-1)*func(t-2,d)/(2*tot));
    double first = 1.0-((double)d*(d-1)/(2*tot))-((double) d/tot);
    double second = 1.0-(1.0*d*(d-1)/(2.0*tot));
    res = max(tem/first,(tem+d*func(t,d-1)/tot));
    return res;
}*/

int main() {
   /* for(int i = 0; i < MX; i++)
        for(int j = 0; j < MX; j++)
            dp[i][j] = -1.0;
    double ans;*/
    int te, ti, t, d;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%d%d", &t, &d);
        printf("Case %d: %.10lf\n", te, (t%2)? 0.0:1.0/(t+1.0));
    }
    return 0;
}
