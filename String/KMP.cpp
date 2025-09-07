vector<int> KMP(string s) {
	int n = s.size() - 1;
	vector<int> nxt(n + 1); // nxt[i] 是字符串 s[1...i] 的最大 border
	for (int i = 2, j = 0; i <= n; i++) {
		while (j > 0 && s[j + 1] != s[i]) {
			j = nxt[j];
		}
		if (s[j + 1] == s[i]) {
			j += 1;
		}
		nxt[i] = j;
	}
	return nxt;
}
vector<array<int, 2>> match(string s, string t) { // t 是不是 s 的子串
	int n = s.size() - 1, m = t.size() - 1;
	auto nxt = KMP(t);
	vector<array<int, 2>> ranges;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j > 0 && t[j + 1] != s[i]) {
			j = nxt[j];
		}
		if (t[j + 1] == s[i]) {
			j += 1;
		}
		if (j == m) {
			ranges.push_back({i - m + 1, i});
		}
	}
	return ranges;
}