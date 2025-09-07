template<class Info, class Tag>
struct LazySegmentTree {
	int n;
	std::vector<Info> info;
	std::vector<Tag> tag;
	LazySegmentTree() : n(0) {}
	LazySegmentTree(int n_, Info v_ = Info()) {
		init(n_, v_);
	}
	template<class T>
	LazySegmentTree(std::vector<T> init_) {
		init(init_);
	}
	void init(int n_, Info v_ = Info()) {
		init(std::vector(n_ + 1, v_));
	}
	template<class T>
	void init(std::vector<T> init_) {
		n = init_.size() - 1;
		info.assign(4 << std::__lg(n + 1), Info());
		tag.assign(4 << std::__lg(n + 1), Tag());
		auto build = [&](auto build, int u, int l, int r) -> void {
			if (l == r) {
				info[u] = {init_[l]};
				return;
			}
			int mid = l + r >> 1;
			build(build, u << 1, l, mid);
			build(build, u << 1 | 1, mid + 1, r);
			pushup(u);
		};
		build(build, 1, 0, n);
	}
	void pushup(int u) {
		info[u] = info[u << 1] + info[u << 1 | 1];
	}
	void apply(int u, const Tag &v) {
		info[u].apply(v);
		tag[u].apply(v);
	}
	void pushdown(int u) {
		apply(u << 1, tag[u]);
		apply(u << 1 | 1, tag[u]);
		tag[u] = Tag();
	}
	void _modify(int u, int l, int r, int x, const Info &v) {
		if (l == r) {
			info[u] = v;
			return;
		}
		int mid = l + r >> 1;
		pushdown(u);
		if (x <= mid) {
			_modify(u << 1, l, mid, x, v);
		} else {
			_modify(u << 1 | 1, mid + 1, r, x, v);
		}
		pushup(u);
	}
	void modify(int p, const Info &v) {
		_modify(1, 0, n, p, v);
	}
	void rangeApply(int u, int l, int r, int x, int y, const Tag &v) {
		if (r < x || l > y) {
			return;
		}
		if (l >= x && r <= y) {
			apply(u, v);
			return;
		}
		int mid = l + r >> 1;
		pushdown(u);
		rangeApply(u << 1, l, mid, x, y, v);
		rangeApply(u << 1 | 1, mid + 1, r, x, y, v);
		pushup(u);
	}
	void Apply(int p, const Tag &v) {
		rangeApply(1, 0, n, p, p, v);
	}
	void rangeApply(int l, int r, const Tag &v) {
		rangeApply(1, 0, n, l, r, v);
	}
	Info _rangeQuery(int u, int l, int r, int x, int y) {
		if (r < x || l > y) {
			return Info();
		}
		if (x <= l && r <= y) {
			return info[u];
		}
		int mid = l + r >> 1;
		pushdown(u);
		if (y <= mid) {
			return _rangeQuery(u << 1, l, mid, x, y);
		} else if (x > mid) {
			return _rangeQuery(u << 1 | 1, mid + 1, r, x, y);
		}
		auto left = _rangeQuery(u << 1, l, mid, x, y);
		auto right = _rangeQuery(u << 1 | 1, mid + 1, r, x, y);
		return left + right;
	}
	Info Query(int p) {
		return _rangeQuery(1, 0, n, p, p);
	}
	Info rangeQuery(int l, int r) {
		return _rangeQuery(1, 0, n, l, r);
	}
	template<class F>
	int findFirst(int u, int l, int r, int x, int y, F &&pred) {
		if (r < x || l > y) {
			return -1;
		}
		if (l >= x && r <= y && !pred(info[u])) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int mid = l + r >> 1;
		int res = findFirst(u << 1, l, mid, x, y, pred);
		if (res == -1) {
			res = findFirst(u << 1 | 1, mid + 1, r, x, y, pred);
		}
		return res;
	}
	template<class F>
	int findFirst(int l, int r, F &&pred) {
		return findFirst(1, 0, n, l, r, pred);
	}
	template<class F>
	int findLast(int u, int l, int r, int x, int y, F &&pred) {
		if (r < x || l > y) {
			return -1;
		}
		if (l >= x && r <= y && !pred(info[u])) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int mid = l + r >> 1;
		int res = findLast(u << 1 | 1, mid + 1, r, x, y, pred);
		if (res == -1) {
			res = findLast(u << 1, l, mid, x, y, pred);
		}
		return res;
	}
	template<class F>
	int findLast(int l, int r, F &&pred) {
		return findLast(1, 0, n, l, r, pred);
	}
};
 
struct Tag {
	
	void apply(const Tag &t) {
		
	}
};
 
struct Info {
	
	void apply(const Tag &t) {
		
	}
};
 
Info operator+(const Info &a, const Info &b) {
	
}

template<class Info, class Tag>
struct TreeChainPartition : LazySegmentTree<Info, Tag> {
	using LazySegmentTree<Info, Tag>::n;
	using LazySegmentTree<Info, Tag>::modify;
	using LazySegmentTree<Info, Tag>::rangeApply;
	using LazySegmentTree<Info, Tag>::rangeQuery;
	
	std::vector<int> d, f, son, sz;
	std::vector<int> dfn, seq, top;
	int cnt;
	std::vector<std::vector<int>> g;
	
	TreeChainPartition(int _n, vector<std::vector<int>> G) : LazySegmentTree<Info, Tag> (_n) {
		g = G;
		d.resize(n + 1);
		f.resize(n + 1);
		son.resize(n + 1);
		sz.resize(n + 1);
		dfn.resize(n + 1);
		seq.resize(n + 1);
		top.resize(n + 1);
		cnt = 0;
		dfs1(1, -1, 0);
		dfs2(1, 1);
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
		dfn[u] = ++cnt;
		seq[cnt] = u;
		top[u] = t;
		if (son[u] == 0) return;
		dfs2(son[u], t);
		for (auto v : g[u]) {
			if (v == f[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	
	void modify_point(int u, const Tag &k) {
		modify(dfn[u], k);
	}
	void modify_path(int u, int v, const Tag &k) {
		while (top[u] != top[v]) {
			if (d[top[u]] < d[top[v]]) swap(u, v);
			rangeApply(dfn[top[u]], dfn[u], k);
			u = f[top[u]];
		}
		if (d[u] > d[v]) swap(u, v);
		rangeApply(dfn[u], dfn[v], k);
	}
	void modify_tree(int u, const Tag &k) {
		rangeApply(dfn[u], dfn[u] + sz[u] - 1, k);
	}
	
	Info query_path(int u, int v) {
		Info ans = Info();
		while (top[u] != top[v]) {
			if (d[top[u]] < d[top[v]]) swap(u, v);
			ans = ans + rangeQuery(dfn[top[u]], dfn[u]);
			u = f[top[u]];
		}
		if (d[u] > d[v]) swap(u, v);
		ans = ans + rangeQuery(dfn[u], dfn[v]);
		return ans;
	}
	Info query_point(int u) {
		return query_path(u, u);
	}
	Info query_tree(int u) {
		return rangeQuery(dfn[u], dfn[u] + sz[u] - 1);
	}
	
	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (d[top[u]] > d[top[v]]) {
				u = f[top[u]];
			} else {
				v = f[top[v]];
			}
		}
		return d[u] < d[v] ? u : v;
	}
	int dist(int u, int v) {
		return d[u] + d[v] - 2 * d[lca(u, v)];
	}
	bool isAncester(int u, int v) {
		return dfn[u] <= dfn[v] && dfn[v] <= dfn[u] + sz[u] - 1;
	}
	int jump(int u, int k) {
		if (d[u] < k) {
			return -1;
		}
		int dx = d[u] - k;
		while (d[top[u]] > dx) {
			u = f[top[u]];
		}
		return seq[dfn[u] - d[u] + dx];
	}
};