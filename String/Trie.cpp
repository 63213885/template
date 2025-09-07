template <typename T>
struct Trie {
	std::vector<std::vector<int>> son;
	std::vector<T> cnt;
	int idx;
	
	Trie(int n, int m) {
		son.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			son[i].resize(m);
		}
		cnt.resize(n + 1);
		idx = 0;
	}
	void insert(string s) {
		int p = 0;
		for (auto c : s) {
			int u = c - 'a';
			if (!son[p][u]) son[p][u] = ++idx;
			p = son[p][u];
		}
		cnt[p] += 1;
	}
	int count(string s) {
		int p = 0;
		for (auto c : s) {
			int u = c - 'a';
			if (!son[p][u]) return 0;
			p = son[p][u];
		}
		return cnt[p];
	}
};