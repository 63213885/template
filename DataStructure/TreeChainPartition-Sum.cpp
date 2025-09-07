template <typename T>
struct SegmentTree {
	struct node {
		int l, r;
		T s, add;
	};
	int n;
	std::vector<node> tr;
	std::vector<T> val;
	
	SegmentTree(int _n) : n(_n) {}
	
	void pushup(int u) {
		tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
	}
	void pushdown(int u) {
		if (tr[u].add == 0) return;
		tr[u << 1].s += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
		tr[u << 1 | 1].s += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
		tr[u << 1].add += tr[u].add;
		tr[u << 1 | 1].add += tr[u].add;
		tr[u].add = 0;
	}
	void build(int u, int l, int r) {
		tr[u] = {l, r, 0, 0};
		if (l == r) {
			tr[u].s = val[l];
			return;
		}
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void build(std::vector<T> arr) {
		val = arr;
		tr.resize(n << 2);
		build(1, 1, n);
	}
	void modify(int u, int l, int r, T x) {
		if (tr[u].l >= l && tr[u].r <= r) {
			tr[u].s += (tr[u].r - tr[u].l + 1) * x;
			tr[u].add += x;
			return;
		}
		int mid = tr[u].l + tr[u].r >> 1;
		pushdown(u);
		if (l <= mid) modify(u << 1, l, r, x);
		if (r > mid) modify(u << 1 | 1, l, r, x);
		pushup(u);
	}
	T query(int u, int l, int r) {
		if (tr[u].l >= l && tr[u].r <= r) return tr[u].s;
		int mid = tr[u].l + tr[u].r >> 1;
		pushdown(u);
		T ans = 0;
		if(l <= mid) ans += query(u << 1, l, r);
		if (r > mid) ans += query(u << 1 | 1, l, r);
		return ans;
	}
};

template <typename T>
struct TreeChainPartition : SegmentTree<T> {
	using SegmentTree<T>::n;
	using SegmentTree<T>::modify;
	using SegmentTree<T>::query;
	
	std::vector<int> d, f, son, sz;
	std::vector<int> dfn, top;
	std::vector<T> a, b;
	int cnt;
	std::vector<std::vector<int>> g;
	
	TreeChainPartition(int _n) : SegmentTree<T> (_n) {
		g.resize(n + 1);
	}
	void add(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void dfs1(int u, int fa, int dep) {
		d[u] = dep, f[u] = fa, sz[u] = 1;
		for (auto v : g[u]) {
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
		for (auto v : g[u]) {
			if (v == f[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void build(std::vector<T> arr) {
		a = arr;
		b.resize(n + 1);
		d.resize(n + 1);
		f.resize(n + 1);
		son.resize(n + 1);
		sz.resize(n + 1);
		dfn.resize(n + 1);
		top.resize(n + 1);
		cnt = 0;
		dfs1(1, -1, 1);
		dfs2(1, 1);
		SegmentTree<T>::build(b);
	}
	void modify_path(int u, int v, T k) {
		while (top[u] != top[v]) {
			if (d[top[u]] < d[top[v]]) swap(u, v);
			modify(1, dfn[top[u]], dfn[u], k);
			u = f[top[u]];
		}
		if (d[u] > d[v]) swap(u, v);
		modify(1, dfn[u], dfn[v], k);
	}
	void modify_tree(int u, T k) {
		modify(1, dfn[u], dfn[u] + sz[u] - 1, k);
	}
	T query_path(int u, int v) {
		T ans = 0;
		while (top[u] != top[v]) {
			if (d[top[u]] < d[top[v]]) swap(u, v);
			ans += query(1, dfn[top[u]], dfn[u]);
			u = f[top[u]];
		}
		if (d[u] > d[v]) swap(u, v);
		ans += query(1, dfn[u], dfn[v]);
		return ans;
	}
	T query_tree(int u) {
		return query(1, dfn[u], dfn[u] + sz[u] - 1);
	}
};