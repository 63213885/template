#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

const int N = 2e5 + 10;
int n, m, k;
int a[N];

struct node {
	int l, r, s, add;
} tr[N << 2];
void pushup(int u) {
	tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}
void pushdown(int u) {
	if (tr[u].add == 0) return;
	tr[u << 1].s = tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
	tr[u << 1 | 1].s = tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
	tr[u << 1].add = tr[u << 1 | 1].add = tr[u].add;
	tr[u].add = 0;
}
void build(int u, int l, int r) {
	tr[u] = {l, r, 0, 0};
	if (l == r) {
		tr[u].s = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r, int x) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].s = (tr[u].r - tr[u].l + 1) * x;
		tr[u].add = x;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	if (l <= mid) modify(u << 1, l, r, x);
	if (r > mid) modify(u << 1 | 1, l, r, x);
	pushup(u);
}
int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].s;
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	int ans = 0;
	if(l <= mid) ans += query(u << 1, l, r);
	if (r > mid) ans += query(u << 1 | 1, l, r);
	return ans;
}
void solve() {
	
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
//  cin >> T;
	while (T--) {
		solve();
	}
	return 0 ^ 0;
}