#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the berthType function below.
 */
string berthType(int n)
{
    // Return the type of berth as described in the output format section.
    n --;
    n %= 8;
    if(n == 0 || n == 3)
        return "LB";
    if(n == 1 || n == 4)
        return "MB";
    if(n == 2 || n == 5)
        return "UB";
    if(n == 6)
        return "SLB";
    return "SUB";

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = berthType(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
