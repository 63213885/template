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
	int n, k;
	cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		if (q.size() && q.front() < i - k + 1) q.pop_front();
		while (q.size() && a[i] <= a[q.back()]) q.pop_back();
		q.push_back(i);
		if (i >= k) cout << a[q.front()] << " \n"[i == n];
	}
	while (q.size()) q.pop_back();
	for (int i = 1; i <= n; i++) {
		if (q.size() && q.front() < i - k + 1) q.pop_front();
		while (q.size() && a[i] >= a[q.back()]) q.pop_back();
		q.push_back(i);
		if (i >= k) cout << a[q.front()] << " \n"[i == n];
	}
	return 0 ^ 0;
}