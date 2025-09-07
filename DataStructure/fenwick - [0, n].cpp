template <typename T>
struct fenwick {
	std::vector<T> tr;
	int n;
	fenwick(int _n) : n(_n) {
		tr.resize(n + 1);
	}
	void add(int x, T k) {
		for ( ; x <= n; x |= x + 1) {
			tr[x] += k;
		}
	}
	T Sum(int x) {
		T ans = 0;
		for ( ; x >= 0; x &= x + 1, x -= 1) {
			ans += tr[x];
		}
		return ans;
	}
	T Sum(int l, int r) {
		return Sum(r) - Sum(l - 1);
	}
};
