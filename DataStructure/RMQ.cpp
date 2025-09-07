template <class Info>
struct RMQ {
	std::vector<int> lg;
	std::vector<std::vector<Info>> f;
	RMQ(std::vector<int> a) : lg(a.size()) {
		int n = a.size() - 1, m = __lg(n) + 1;
		f.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			f[i].resize(m + 1);
			f[i][0] = {a[i]};
			if (i) lg[i] = __lg(i);
		}
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i++) {
				f[i][j] = f[i][j - 1] + f[i + (1 << j - 1)][j - 1];
			}
		}
	}
	Info Query(int l, int r) {
		int k = lg[r - l + 1];
		return f[l][k] + f[r - (1 << k) + 1][k];
	}
};
struct Info {
	int x;
	friend Info operator+(const Info &a, const Info &b) {
		
	}
};