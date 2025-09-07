#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

const int N = 1e6 + 10;
int n, m, k;
int B[N];

void add(int x, int k) {
	for ( ; x <= n; x += x & -x) {
		B[x] += k;
	}
}
int sum(int x) {
	int ans = 0;
	for ( ; x > 0; x -= x & -x) {
		ans += B[x];
	}
	return ans;
}
int query(int l, int r) {
	return sum(r) - sum(l - 1);
}
void solve() {
	
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
//  cin >> T;
	while (T--) {
		solve();
	}
	return 0 ^ 0;
}