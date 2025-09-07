template <typename T>
struct SegmentTree {
	struct node {
		int l, r;
		T sco, cnt;
	};
	std::vector<node> tr;
	int n, idx, root;
	
	SegmentTree(int _n, int L, int R) : n(_n) {
		int len = R - L + 1, cnt = n;
		for (int N = 1; len > 1; N <<= 1) {
			if (N >= n) cnt += n;
			len -= len >> 1;
		}
		tr.resize(cnt + n + 1);
		idx = root = 0;
	}
	
	void pushup(int u) {
		tr[u].sco = tr[tr[u].l].sco + tr[tr[u].r].sco;
		tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
	}
	void modify(int &u, int L, int R, int a, T b) {
		if (!u) u = ++idx;
		if (L == R) {
			tr[u].sco += L * b;
			tr[u].cnt += b;
			return;
		}
		int mid = L + R >> 1;
		if (a <= mid) modify(tr[u].l, L, mid, a, b);
		else modify(tr[u].r, mid + 1, R, a, b);
		pushup(u);
	}
	T query(int u, int L, int R, int x) {
		if (x > tr[u].cnt) return -1;
		if (L == R) return x * L;
		int mid = L + R >> 1;
		if (x <= tr[tr[u].r].cnt) {
			return query(tr[u].r, mid + 1, R, x);
		} else {
			return query(tr[u].l, L, mid, x - tr[tr[u].r].cnt) + tr[tr[u].r].sco;
		}
	}
};