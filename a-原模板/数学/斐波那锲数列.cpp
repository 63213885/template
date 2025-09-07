#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

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

using namespace std;
using LL = long long;
using PII = pair<int, int>;
namespace Debug {
	template <typename U, typename T>
	void print_arg(const U &Arg, const T &arg) {
		cerr << Arg << " = " << arg;
	}
	template <typename T>
	void err(string Arg, const T &arg) {
		print_arg(Arg, arg); cerr << endl;
	}
	template <typename T, typename... Ts>
	void err(string Arg, const T &arg, const Ts &...args) {
		size_t pos = Arg.find(',');
		print_arg(Arg.substr(0, pos), arg); cerr << ",";
		err(Arg.substr(pos + 1), args...);
	}
	#define debug(args...) err(#args, ##args)
}
using namespace Debug;
/*<------------------------------------------------------------->*/
const int N = 1e5 + 10, M = 1e9 + 7;
int n, m, k;

void mul(int c[2][2], int a[2][2], int b[2][2]) {
	int t[2][2] = {0, 0, 0, 0};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % M;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c[i][j] = t[i][j];
		}
	}
}
 
int f(int n) {
	if (!n) return 0;
	int a[2][2] = {{1, 1}, {1, 0}};
	int res[2][2] = {1, 0, 0, 1};
	int k = n - 1;
	while(k) {
		if (k & 1) mul(res, res, a);
		mul(a, a, a);
		k >>= 1;
	}
	int ans[2] = {0, 0}, x[2] = {1, 0};
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			ans[i] = (ans[i] + x[j] * res[j][i]) % M;
		}
	}
	return ans[0];
}
void solve(int test_i) {
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(3);
	int T = 1;
//	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}