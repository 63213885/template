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
int d[N], f[N][25];
std::vector<int> e[N];

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	for (int k = 21; k >= 0; k--) {
		if (d[f[a][k]] >= d[b]) a = f[a][k];
	}
	if (a == b) return a;
	for (int k = 21; k >= 0; k--) {
		if (f[a][k] != f[b][k]) {
			a = f[a][k]; b = f[b][k];
		}
	}
	return f[a][0];
}
void lca_init() {
	queue<int> q;
	q.push(1);
	d[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (d[v]) continue;
			d[v] = d[u] + 1;
			f[v][0] = u;
			for (int k = 1; k <= 21; k++) {
				f[v][k] = f[f[v][k - 1]][k - 1];
			}
			q.push(v);
		}
	}
}
void solve(int test_i) {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	lca_init();
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(10);
	int T = 1;
//	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}