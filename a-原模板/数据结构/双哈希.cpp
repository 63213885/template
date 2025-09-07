#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val) cerr << #val << " = " << (val) << endl
#define x first
#define y second
const int N = 2e5 + 10;
const int M1 = 1e9 + 7, P1 = 131;
const int M2 = 1e9 + 9, P2 = 13331;
int n, m, k;
pair<int, int> h[N], hi[N], p[N];
char s[N];

pair<int, int> get(int l, int r) {
	int h1 = (h[r].x - 1ll * h[l - 1].x * p[r - l + 1].x % M1 + M1) % M1;
	int h2 = (h[r].y - 1ll * h[l - 1].y * p[r - l + 1].y % M2 + M2) % M2;
	return pair<int, int> (h1, h2);
}
pair<int, int> geti(int l, int r) {
	int h1 = (hi[l].x - 1ll * hi[r + 1].x * p[r - l + 1].x % M1 + M1) % M1;
	int h2 = (hi[l].y - 1ll * hi[r + 1].y * p[r - l + 1].y % M2 + M2) % M2;
	return pair<int, int> (h1, h2);
}
bool check(int l, int r) {
	return get(l, r) == geti(l, r);
}
void hash_init(int n) {
	p[0] = {1, 1};
	for (int i = 1; i <= n; i++) {
		p[i].x = 1ll * p[i - 1].x * P1 % M1;
		p[i].y = 1ll * p[i - 1].y * P2 % M2;
	}
	for (int i = 1; i <= n; i++) {
		h[i].x = (1ll * h[i - 1].x * P1 + s[i]) % M1;
		h[i].y = (1ll * h[i - 1].y * P2 + s[i]) % M2;
	}
	for (int i = n; i >= 1; i--) {
		hi[i].x = (1ll * hi[i + 1].x * P1 + s[i]) % M1;
		hi[i].y = (1ll * hi[i + 1].y * P2 + s[i]) % M2;
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