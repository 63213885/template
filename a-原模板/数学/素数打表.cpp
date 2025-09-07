#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(val)  \
	cerr << #val << " = " << (val) << endl

const int N = 1e6 + 10;
int n, m, k;
int p[N], cnt, minp[N];
bool book[N];

void prime_init(int n) {
	for (int i = 2; i <= n; i++) {
		if (book[i] == 0) {
			p[cnt++] = i;
			minp[i] = i;
		}
		for (int j = 0; p[j] <= n / i; j++) {
			book[p[j] * i] = 1;
			minp[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
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