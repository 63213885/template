#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

const int N = 1e6 + 10;
const int M = 998244353;
int n, m, k;
int fac[N], inv[N];

int qmi(int n, int k) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = ans * n % M;
		n = n * n % M;
		k = k / 2;
	}
	return ans;
}
int Inv(int x) {
	return qmi(x, M - 2);
}
int C(int a, int b) {
	if (a < b) return 0;
	return fac[a] * inv[b] % M * inv[a - b] % M;
}
int A(int a, int b) {
	if (a < b) return 0;
	return fac[a] * inv[a - b] % M;
}
int H(int a, int b) {
	return C(a + b - 1, b);
}
void C_init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	inv[n] = qmi(fac[n], M - 2);
	for (int i = n - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % M;
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