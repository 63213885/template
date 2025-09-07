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
const int N = 2e5 + 10;
const int M = 25;
int n, m, k;
int a[N], lg[N], f[N][M], g[N][M];

pair<int, int> RMQ(int l, int r) {
	int k = lg[r - l + 1];
	int maxx = max(f[l][k], f[r - (1 << k) + 1][k]);
	int minn = min(g[l][k], g[r - (1 << k) + 1][k]);
	return pair<int, int> (maxx, minn);
}
void RMQ_init(int a[], int n) {
	for (int j = 0; j < M; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if (j == 0) {
				f[i][j] = g[i][j] = a[i];
			} else {
				f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
				g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) lg[i] = log2(i);
}
void solve(int test_i) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	RMQ_init(a, n);
	int n = 10, m = 20, k = 30;
	std::vector<std::vector<int>> a(n, std::vector<int> (m));
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int T = 1;
//	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}