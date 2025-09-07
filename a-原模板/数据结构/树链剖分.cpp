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
const int N = 1e5 + 10;
int n, m, k;
int d[N], f[N], son[N], sz[N];
int a[N], b[N], dfn[N], cnt, top[N];
std::vector<int> e[N];

void dfs1(int u, int fa, int dep) {
	d[u] = dep, f[u] = fa, sz[u] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs1(v, u, dep + 1);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int t) {
	dfn[u] = ++cnt, b[cnt] = a[u], top[u] = t;
	if (son[u] == 0) return;
	dfs2(son[u], t);
	for (auto v : e[u]) {
		if (v == f[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
struct node {
	int l, r, s, add;
} tr[N << 2];
void pushup(int u) {
	tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}
void pushdown(int u) {
	if (tr[u].add == 0) return;
	tr[u << 1].add += tr[u].add;
	tr[u << 1 | 1].add += tr[u].add;
	tr[u << 1].s += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
	tr[u << 1 | 1].s += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
}
void build(int u, int l, int r) {
	tr[u] = {l, r, 0, 0};
	if (l == r) return void(tr[u].s = b[r]);
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r, int x) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].s += x * (tr[u].r - tr[u].l + 1);
		tr[u].add += x;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	if (l <= mid) modify(u << 1, l, r, x);
	if (r > mid) modify(u << 1 | 1, l, r, x);
	pushup(u);
}
int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r)return tr[u].s;
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	int ans = 0;
	if (l <= mid) ans += query(u << 1, l, r);
	if (r > mid) ans += query(u << 1 | 1, l, r);
	return ans;
}
void modify_path(int u, int v, int k) {
	while (top[u] != top[v]) {
		if (d[top[u]] < d[top[v]]) swap(u, v);
		modify(1, dfn[top[u]], dfn[u], k);
		u = f[top[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	modify(1, dfn[u], dfn[v], k);
}
void modify_tree(int u, int k) {
	modify(1, dfn[u], dfn[u] + sz[u] - 1, k);
}
int query_path(int u, int v) {
	int ans = 0;
	while (top[u] != top[v]) {
		if (d[top[u]] < d[top[v]]) swap(u, v);
		ans += query(1, dfn[top[u]], dfn[u]);
		u = f[top[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	ans += query(1, dfn[u], dfn[v]);
	return ans;
}
int query_tree(int u) {
	return query(1, dfn[u], dfn[u] + sz[u] - 1);
}

void solve(int test_i) {
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int T = 1;
	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}