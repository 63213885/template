struct RMQ_2D {
	int n, m;
	std::vector<std::vector<std::vector<std::vector<int>>>> f;
	std::vector<std::vector<std::vector<std::vector<int>>>> g;
	RMQ_2D(std::vector<std::vector<int>> a) : n(a.size() - 1), m(a[0].size() - 1) {
		f.resize(n + 1);
		g.resize(n + 1);
		int N = __lg(n) + 1, M = __lg(m) + 1;
		for (int i = 0; i <= n; i++) {
			f[i].resize(m + 1);
			g[i].resize(m + 1);
			for (int j = 0; j <= m; j++) {
				f[i][j].resize(N + 1);
				g[i][j].resize(N + 1);
				for (int k = 0; k <= N; k++) {
					g[i][j][k].resize(M + 1);
					f[i][j][k].resize(M + 1);
				}
			}
		}
		for (int k = 0; k <= N; k++) {
			for (int l = 0; l <= M; l++) {
				for (int i = 1; i + (1 << k) - 1 <= n; i++) {
					for (int j = 1; j + (1 << l) - 1 <= m; j++) {
						if (k == 0 && l == 0) {
							f[i][j][k][l] = a[i][j];
							g[i][j][k][l] = a[i][j];
						} else if (k == 0) {
							f[i][j][k][l] = max(f[i][j][k][l - 1], f[i][j + (1 << l - 1)][k][l - 1]);
							g[i][j][k][l] = min(g[i][j][k][l - 1], g[i][j + (1 << l - 1)][k][l - 1]);
						} else if (l == 0) {
							f[i][j][k][l] = max(f[i][j][k - 1][l], f[i + (1 << k - 1)][j][k - 1][l]);
							g[i][j][k][l] = min(g[i][j][k - 1][l], g[i + (1 << k - 1)][j][k - 1][l]);
						} else {
							f[i][j][k][l] = max({f[i][j][k - 1][l - 1], f[i + (1 << k - 1)][j][k - 1][l - 1], f[i][j + (1 << l - 1)][k - 1][l - 1], f[i + (1 << k - 1)][j + (1 << l - 1)][k - 1][l - 1]});
							g[i][j][k][l] = min({g[i][j][k - 1][l - 1], g[i + (1 << k - 1)][j][k - 1][l - 1], g[i][j + (1 << l - 1)][k - 1][l - 1], g[i + (1 << k - 1)][j + (1 << l - 1)][k - 1][l - 1]});
						}
					}
				}
			}
		}
	}
	int Max(int x1, int y1, int x2, int y2) {
		int k = __lg(x2 - x1 + 1) / __lg(2);
		int l = __lg(y2 - y1 + 1) / __lg(2);
		return max({f[x1][y1][k][l], f[x2 - (1 << k) + 1][y1][k][l], f[x1][y2 - (1 << l) + 1][k][l], f[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]});
	};
	int Min(int x1, int y1, int x2, int y2) {
		int k = __lg(x2 - x1 + 1) / __lg(2);
		int l = __lg(y2 - y1 + 1) / __lg(2);
		return min({g[x1][y1][k][l], g[x2 - (1 << k) + 1][y1][k][l], g[x1][y2 - (1 << l) + 1][k][l], g[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]});
	};
};