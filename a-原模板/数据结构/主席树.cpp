#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(var)	\
	cout << #var << " = " << var << endl

const int N = 2e5 + 10;
int n, m, k;
int len, idx, a[N], b[N], root[N];

struct node {
	int l, r, s;
} tr[N * 21];	//	n*log2(n) 个结点 
int find(int x) {
	return lower_bound(b + 1, b + 1 + len, x) - b;
}
int build(int l, int r) {
	int u = ++idx;
	tr[u].s = 0;
	if (l == r) return u;
	int mid = l + r >> 1;
	tr[u].l = build(l, mid);
	tr[u].r = build(mid + 1, r);
	return u;
}
int insert(int p, int l, int r, int x) {
	int u = ++idx;
	tr[u] = tr[p];
	if (l == r) return tr[u].s++, u;
	int mid = l + r >> 1;
	if (x <= mid) tr[u].l = insert(tr[p].l, l, mid, x);
	else tr[u].r = insert(tr[p].r, mid+1, r, x);
	tr[u].s = tr[tr[u].l].s + tr[tr[u].r].s;
	return u;
}
// 大于等于 k 的个数 
int query1(int x, int y, int l, int r, int k) {
	if (k > b[r]) return 0;
	if (k <= b[l]) return tr[x].s - tr[y].s;
	int mid = l + r >> 1;
	int ans = 0;
	if(k <= b[mid]) {
		ans += tr[tr[x].r].s - tr[tr[y].r].s;
		ans += query1(tr[x].l, tr[y].l, l, mid, k);
	} else {
		ans += query1(tr[x].r, tr[y].r, mid+1, r, k);
	}
	return ans;
}
// 小于等于 k 的个数 
int query2(int x, int y, int l, int r, int k) {
	if(k >= b[r]) return tr[x].s - tr[y].s;
	if (k < b[l]) return 0;
	int mid = l + r >> 1;
	int ans = 0;
	if(k <= b[mid]) {
		ans += query2(tr[x].l, tr[y].l, l, mid, k);
	} else {
		ans += tr[tr[x].l].s - tr[tr[y].l].s;
		ans += query2(tr[x].r, tr[y].r, mid+1, r, k);
	}
	return ans;
}
// 大于 k 的个数 
int query3(int x, int y, int l, int r, int k) {
	if(k >= b[r]) return 0;
	if(k < b[l]) return tr[x].s - tr[y].s;
	int mid = l + r >> 1;
	int ans = 0;
	if(k <= b[mid]) {
		ans += tr[tr[x].r].s - tr[tr[y].r].s;
		ans += query3(tr[x].l, tr[y].l, l, mid, k);
	} else {
		ans += query3(tr[x].r, tr[y].r, mid+1, r, k);
	}
	return ans;
}
// 小于 k 的个数 
int query4(int x, int y, int l, int r, int k) {
	if(k > b[r]) return tr[x].s - tr[y].s;
	if(k <= b[l]) return 0;
	int mid = l + r >> 1;
	int ans = 0;
	if(k <= b[mid]) {
		ans += query4(tr[x].l, tr[y].l, l, mid, k);
	} else {
		ans += tr[tr[x].l].s - tr[tr[y].l].s;
		ans += query4(tr[x].r, tr[y].r, mid+1, r, k);
	}
	return ans;
}
// 等于 k 的个数 
int query5(int x, int y, int l, int r, int k) {
	if(l == r) return k == b[l] ? tr[x].s - tr[y].s : 0;
	int mid = l + r >> 1;
	if(k <= b[mid]) return query5(tr[x].l, tr[y].l, l, mid, k);
	else return query5(tr[x].r, tr[y].r, mid+1, r, k);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	len = unique(b + 1, b + 1 + n) - b - 1;

	root[0] = build(1, len);
	for (int i = 1; i <= n; i++) {
		root[i] = insert(root[i-1], 1, len, find(a[i]));
	}

	/*------------------------------------*/

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
