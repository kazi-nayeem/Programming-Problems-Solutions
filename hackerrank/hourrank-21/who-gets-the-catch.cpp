#include <bits/stdc++.h>

using namespace std;

int whoGetsTheCatch(int n, int x, vector < int > X, vector < int > V)
{
    // Complete this function
    int cnt = 1, pos = 0;
    for(int i = 1; i < n; i++)
    {
        if(X[i]*V[pos] < X[pos]*V[i])
        {
            cnt = 1;
            pos = i;
        }else if(X[i]*V[pos] == X[pos]*V[i])
        {
            cnt++;
        }
    }
    if(cnt == 1) return pos;
    return -1;
}

int main()
{
    //  Return the index of the catcher who gets the catch, or -1 if no one gets the catch.
    int n;
    int x;
    cin >> n >> x;
    vector<int> X(n);
    for(int X_i = 0; X_i < n; X_i++)
    {
        cin >> X[X_i];
        X[X_i] = abs(x-X[X_i]);
    }
    vector<int> V(n);
    for(int V_i = 0; V_i < n; V_i++)
    {
        cin >> V[V_i];
    }
    int result = whoGetsTheCatch(n, x, X, V);
    cout << result << endl;
    return 0;
}
