struct tarjan {
	int timestamp;
	vector<int> dfn, low, id;
	vector<vector<array<int, 2>>> g;
	stack<int> st;
	vector<bool> is_bridge;
	vector<vector<int>> dcc;
	
	tarjan(int n, int m, vector<int> &x, vector<int> &y) {
		g.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			g[x[i]].push_back({y[i], i});
			g[y[i]].push_back({x[i], i});
		}
		dfn.resize(n + 1);
		low.resize(n + 1);
		timestamp = 0;
		id.resize(n + 1);
		is_bridge.resize(m + 1);
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) {
				dfs(i, -1);
			}
		}
	}
	void dfs(int u, int fa) {
		dfn[u] = low[u] = ++timestamp;
		st.push(u);
		for (auto &[v, i] : g[u]) {
			if (v == fa) continue;
			if (!dfn[v]) {
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if(low[v] > dfn[u]) {
					is_bridge[i] = true;
				}
			} else if (dfn[v] < dfn[u]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			vector<int> t;
			do {
				t.push_back(st.top());
				st.pop();
				id[t.back()] = dcc.size() + 1;
			} while (t.back() != u);
			dcc.push_back(t);
		}
	}
};