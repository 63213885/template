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
	void modify(int u, int l, int r, int x, const Info &v) {
		if (l == r) {
			info[u] = v;
			return;
		}
		int mid = l + r >> 1;
		pushdown(u);
		if (x <= mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid + 1, r, x, v);
		}
		pushup(u);
	}
	void modify(int p, const Info &v) {
		modify(1, 0, n, p, v);
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
	Info rangeQuery(int u, int l, int r, int x, int y) {
		if (r < x || l > y) {
			return Info();
		}
		if (x <= l && r <= y) {
			return info[u];
		}
		int mid = l + r >> 1;
		pushdown(u);
		if (y <= mid) {
			return rangeQuery(u << 1, l, mid, x, y);
		} else if (x > mid) {
			return rangeQuery(u << 1 | 1, mid + 1, r, x, y);
		}
		auto left = rangeQuery(u << 1, l, mid, x, y);
		auto right = rangeQuery(u << 1 | 1, mid + 1, r, x, y);
		return left + right;
	}
	Info Query(int p) {
		return rangeQuery(1, 0, n, p, p);
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
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
		pushdown(u);
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
		pushdown(u);
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