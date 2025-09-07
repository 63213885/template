template<typename T>
struct fenwick2D{
	vector<vector<T>> tr;
	int n, m;
	fenwick2D(int _n, int _m) : n(_n), m(_m) {
		tr.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			tr[i].resize(m + 1);
		}
	}
	void add(int x, int y, const T &val){ // 1 <= x <= n, 1 <= y <= m
		for(int i = x; i <= n; i += i & -i) {
			for(int j = y; j <= m; j += j & -j) {
				tr[i][j] += val;
			}
		}
	}
	T Sum(int x, int y) { // 1 <= x <= n, 1 <= y <= m
		T res = 0;
		for(int i = x; i > 0; i -= i & -i) {
			for(int j = y; j > 0; j -= j & -j) {
				res += tr[i][j];
			}
		}
		return res;
	}
	T Sum(int x1, int y1, int x2, int y2) {  // sum[x1..x2, y1..y2]
		return Sum(x2, y2) - Sum(x2, y1 - 1) - Sum(x1 - 1, y2) + Sum(x1 - 1, y1 - 1);
	}
};
