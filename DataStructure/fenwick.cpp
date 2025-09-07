template <typename T>
struct fenwick {
	int n;
	std::vector<T> tr;
	fenwick(int _n = 0) {
		n = _n + 1;
		tr.assign(n, T{});
	}
	void add(int x, const T &v) {
		for (int i = x + 1; i <= n; i += i & -i) {
			tr[i - 1] = tr[i - 1] + v;
		}
	}
	T Sum(int x) {
		T ans{};
		for (int i = x + 1; i > 0; i -= i & -i) {
			ans = ans + tr[i - 1];
		}
		return ans;
	}
	T Sum(int l, int r) {
		return Sum(r) - Sum(l - 1);
	}
	int kth(const T &k) {
		int x = 0;
		T cur{};
		for (int i = 1 << std::__lg(n); i; i /= 2) {
			if (x + i <= n && cur + tr[x + i - 1] < k) {
				x += i;
				cur = cur + tr[x - 1];
			}
		}
		return x;
	}
};