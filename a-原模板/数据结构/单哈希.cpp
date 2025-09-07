#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

const int N = 2e5 + 10;
const int M = 1610612741;
const int P = 131;
int n, m, k;
int h[N], hi[N], p[N];
char s[N];

int get(int l, int r) {
	return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
}
int geti(int l, int r) {
	return (hi[l] - hi[r + 1] * p[r - l + 1] % M + M) % M;
}
bool check(int l, int r) {
	return get(l, r) == geti(l, r);
}
void hash_init(int n) {
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P % M;
	}
	for (int i = 1; i <= n; i++) {
		h[i] = (h[i - 1] * P + s[i]) % M;
	}
	for (int i = n; i >= 1; i--) {
		hi[i] = (hi[i + 1] * P + s[i]) % M;
	}
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