#include <bits/stdc++.h>

using namespace std;
using LL = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define dbg(...) "jzz2.0"
#define debug(...) "jzz2.0"
#endif

#define int LL
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) (x).begin() + 1, (x).end()

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n = 10;
	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << rng() % 20 + 1 << " \n"[i == n];
	}
	return 0 ^ 0;
}