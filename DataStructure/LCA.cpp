template <typename T>
struct LCA {
	int m;
	std::vector<int> d;
	std::vector<T> dist;
	std::vector<std::vector<pair<int, T>>> g;
	std::vector<std::vector<int>> f;
	LCA(int n) : d(n + 1), dist(n + 1), g(n + 1), f(n + 1) {
		m = __lg(n) + 1;
		for (int i = 0; i <= n; i++) {
			f[i].resize(m + 1);
		}
	}
	void add(int u, int v, T w = 1) {
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	void build(int root = 1) {
		queue<int> q;
		q.push(root);
		d[root] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto [v, w] : g[u]) {
				if (d[v]) continue;
				d[v] = d[u] + 1;
				dist[v] = dist[u] + w;
				f[v][0] = u;
				for (int k = 1; k <= m; k++) {
					f[v][k] = f[f[v][k - 1]][k - 1];
				}
				q.push(v);
			}
		}
	}
	int lca(int a, int b) {
		if (d[a] < d[b]) swap(a, b);
		for (int k = m; k >= 0; k--) {
			if (d[f[a][k]] >= d[b]) a = f[a][k];
		}
		if (a == b) return a;
		for (int k = m; k >= 0; k--) {
			if (f[a][k] != f[b][k]) {
				a = f[a][k]; b = f[b][k];
			}
		}
		return f[a][0];
	}
	T dis(int u, int v) {
		return dist[u] + dist[v] - dist[lca(u, v)] * 2;
	}
};