#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "jzz2.0"
#endif

#define int long long

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	int L = r - l + 1;
	int x = rng();
	return l + (x % L + L) % L;
}
signed main() {
	int n = rnd(1, 2000), p = rnd(1, 2000);
	cout << n << " " << p << endl;
	for (int i = 1; i <= n; i++) {
		int x = rnd(1, 1e9);
		cout << x << " \n"[i == n];
	}
	return 0 ^ 0;
}