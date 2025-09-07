#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define range(x, l, r) x.begin() + l, x.begin() + r + 1
#define debug(val...) cerr << (#val) << " = ";err(val);

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T>
void err(T arg) {cerr << arg << endl;}
template <typename T, typename... Args>
void err(T arg, Args... args) {
	cerr << arg << ", "; err(args...);
}
/*<------------------------------------------------->*/

const int N = 2e5 + 10;
int n, m, k;

void solve(int test_i) {
	
}
signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	int T = 1;
//	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}