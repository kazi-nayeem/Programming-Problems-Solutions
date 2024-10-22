#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class BichromeBoard {
public:
    string ableToDraw(vector <string> board) {
        queue<pair<int, int> > qu;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '?') continue;
                qu.push(make_pair(i,j));
            }
        }
        int xx[] = {0,0,1,-1};
        int yy[] = {1,-1,0,0};
        while(!qu.empty()) {
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();

            for(int i = 0; i < 4; i++) {
                int tx = x+xx[i];
                int ty = y+yy[i];
                if(tx < 0 || ty < 0 || tx >= board.size() || ty >= board[0].size()) continue;
                if(board[tx][ty] == '?') {
                    if(board[x][y] == 'B') {
                        board[tx][ty] = 'W';
                    } else {
                        board[tx][ty] = 'B';
                    }
                    qu.push(make_pair(tx,ty));
                } else if(board[tx][ty] == board[x][y]) {
                    return "Impossible";
                }
            }

        }
        return "Possible";
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    BichromeBoard *obj;
    string answer;
    obj = new BichromeBoard();
    clock_t startTime = clock();
    answer = obj->ableToDraw(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <string> p0;
    string p1;

    {
        // ----- test 0 -----
        string t0[] = {"W?W","?" "?B","?" "?" "?"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"W?" "?W"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Impossible";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"?" "?"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"W?" "?" "?","?" "?B?","W?" "?" "?","?" "?" "?W"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"W?" "?" "?","?" "?B?","W?" "?" "?","?B?W"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Impossible";
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        string t0[] = {"B"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
