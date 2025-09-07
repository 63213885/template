template <typename T>
struct PrefixSum2D {
	int n, m;
	vector<vector<T>> s;
	PrefixSum2D(int _n, int _m) : n(_n), m(_m), a(n + 1, vector<T>(m + 1, 0)){}
	PrefixSum2D(vector<vector<T>> a) {
		n = a.size() - 1, m = a[0].size() - 1;
		s.assign(n + 1, vector<T>(m + 1, 0));
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++)
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	}
	T sum(int x1, int y1, int x2, int y2) {
		return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
	}
};