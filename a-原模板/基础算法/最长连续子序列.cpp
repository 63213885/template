#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)	\
	cerr << #val << " = " << (val) << endl

const int N = 1e6 + 10;
int n, m, k;
int a[N], s[N];

bool check(int d) {
	int minn = 1e18;
	for (int i = 1; i <= n; i++) {
		if(i >= d) minn = min(minn, s[i - d]);
		if (s[i] - minn > 0) return 1;
	}
	return 0;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i] - 100;
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	}
	return 0 ^ 0;
}