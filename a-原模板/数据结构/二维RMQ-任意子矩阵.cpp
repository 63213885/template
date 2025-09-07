#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

//#define int long long
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
constexpr bool multiple_test_cases = 0;

auto RMQ_init(std::vector<std::vector<int>> a, int n, int m) {
	int N = __lg(n) + 1, M = __lg(m) + 1;
	std::vector<std::vector<std::vector<std::vector<int>>>> g(n + 1, 
		std::vector<std::vector<std::vector<int>>> (m + 1, 
			std::vector<std::vector<int>> (N, 
				std::vector<int> (M))));
	
	for (int k = 0; (1 << k) <= n; k++) {
		for (int l = 0; (1 << l) <= m; l++) {
			for (int i = 1; i + (1 << k) - 1 <= n; i++) {
				for (int j = 1; j + (1 << l) - 1 <= m; j++) {
					if (k == 0 && l == 0) {
						g[i][j][k][l] = a[i][j];
					} else if (k == 0) {
						g[i][j][k][l] = min(g[i][j][k][l - 1], g[i][j + (1 << (l - 1))][k][l - 1]);
					} else if (l == 0) {
						g[i][j][k][l] = min(g[i][j][k - 1][l], g[i + (1 << (k - 1))][j][k - 1][l]);
					} else {
						g[i][j][k][l] = min({g[i][j][k - 1][l - 1], 
							g[i + (1 << (k - 1))][j][k - 1][l - 1], 
							g[i][j + (1 << (l - 1))][k - 1][l - 1], 
							g[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1]});
					}
				}
			}
		}
	}
	return g;
}
void solve(int test_i) {
	int n, m;
	cin >> n >> m;
	std::vector<std::vector<int>> a(n + 1, std::vector<int> (m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	auto g = RMQ_init(a, n, m);
	auto RMQ = [&](int x1, int y1, int x2, int y2) {
		int k = __lg(x2 - x1 + 1) / __lg(2);
		int l = __lg(y2 - y1 + 1) / __lg(2);
		return min({g[x1][y1][k][l], g[x2 - (1 << k) + 1][y1][k][l],
					g[x1][y2 - (1 << l) + 1][k][l],
					g[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]});
	};
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int T = 1;
	if (multiple_test_cases) {
		cin >> T;
	}
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}