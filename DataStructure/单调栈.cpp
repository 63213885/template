#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "jzz2.0"
#endif

#define int long long
#define endl "\n"

using namespace std;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	std::vector<int> LMin(n + 1);
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()] >= a[i]) st.pop();
		LMin[i] = st.size() ? a[st.top()] : -1;
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << LMin[i] << " \n"[i == n];
	}
	return 0 ^ 0;
}