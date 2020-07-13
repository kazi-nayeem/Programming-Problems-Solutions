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

typedef long long ll;

class ProblemSets {
public:
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
        ll low = 0, hi = E+EM+10;
        ll ans = 0;
        while(low<=hi)
        {
            ll mid = (hi+low)/2;
            if(func(E,EM,M,MH,H,mid))
            {
                low = mid+1;
                ans = max(ans,mid);
            }else{
                hi = mid-1;
            }
        }
        return ans;
	}
	bool func(ll E, ll EM, ll M, ll MH, ll H, ll v)
    {
        if(E<v)
        {
            EM -= v-E;
        }
        if(H<v)
        {
            MH -= v-H;
        }
        if(EM < 0 || MH < 0) return false;
        if(EM+M+MH<v) return false;
        return true;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, long long p2, long long p3, long long p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	ProblemSets *obj;
	long long answer;
	obj = new ProblemSets();
	clock_t startTime = clock();
	answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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

	long long p0;
	long long p1;
	long long p2;
	long long p3;
	long long p4;
	long long p5;

	{
	// ----- test 0 -----
	p0 = 2ll;
	p1 = 2ll;
	p2 = 1ll;
	p3 = 2ll;
	p4 = 2ll;
	p5 = 3ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 100ll;
	p1 = 100ll;
	p2 = 100ll;
	p3 = 0ll;
	p4 = 0ll;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 657ll;
	p1 = 657ll;
	p2 = 657ll;
	p3 = 657ll;
	p4 = 657ll;
	p5 = 1095ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 1ll;
	p1 = 2ll;
	p2 = 3ll;
	p3 = 4ll;
	p4 = 5ll;
	p5 = 3ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 1000000000000000000ll;
	p1 = 1000000000000000000ll;
	p2 = 1000000000000000000ll;
	p3 = 1000000000000000000ll;
	p4 = 1000000000000000000ll;
	p5 = 1666666666666666666ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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