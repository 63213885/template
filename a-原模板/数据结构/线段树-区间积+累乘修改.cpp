#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

typedef long long LL;
const int N = 1e5 + 10;
const int M = 998244353;
int n, m, k;

LL qmi(LL n, LL k) {
	LL ans = 1;
	while (k) {
		if (k & 1) ans = ans * n % M;
		n = n * n % M;
		k = k / 2;
	}
	return ans;
}
struct node {
	int l, r, x, lazy;
} tr[N << 2];
void pushup(int u) {
	tr[u].x = 1ll * tr[u << 1].x * tr[u << 1 | 1].x % M;
}
void pushdown(int u) {
	if (tr[u].lazy != 1) return ;
	tr[u << 1].x = tr[u << 1].x * tr[u].lazy % M;
	tr[u << 1 | 1].x = tr[u << 1 | 1].x * tr[u].lazy % M;
	tr[u << 1].lazy = tr[u << 1].lazy * tr[u].lazy % M;
	tr[u << 1 | 1].lazy = tr[u << 1 | 1].lazy * tr[u].lazy % M;
	tr[u].lazy = 1;
}
void build(int u, int l, int r) {
	tr[u] = {l, r, 1, 1};
	if (l == r) return;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r, int k) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].x = tr[u].x * k % M;
		tr[u].lazy = tr[u].lazy * k % M;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid) modify(u << 1, l, r, k);
	if (r > mid) modify(u << 1 | 1, l, r, k);
	pushup(u);
}
int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		return tr[u].x;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	LL ans = 1;
	if (l <= mid) ans = ans * query(u << 1, l, r) % M;
	if (r > mid) ans = ans * query(u << 1 | 1, l, r) % M;
	return ans;
}

void solve() {
	
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	}
	return 0 ^ 0;
}
