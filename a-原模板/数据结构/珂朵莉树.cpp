#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define range(x, l, r) x.begin() + l, x.begin() + r + 1

using namespace std;
using LL = long long;
using PII = pair<int, int>;
namespace Debug {
	template <typename U, typename T>
	void print_arg(const U &Arg, const T &arg) {
		cerr << Arg << " = " << arg;
	}
	template <typename T>
	void err(string Arg, const T &arg) {
		print_arg(Arg, arg); cerr << endl;
	}
	template <typename T, typename... Ts>
	void err(string Arg, const T &arg, const Ts &...args) {
		size_t pos = Arg.find(',');
		print_arg(Arg.substr(0, pos), arg); cerr << ",";
		err(Arg.substr(pos + 1), args...);
	}
	#define debug(args...) err(#args, ##args)
}
using namespace Debug;
/*<------------------------------------------------------------->*/
const int N = 2e5 + 10;
int n, m, k;

struct odt {
	int l, r;
	mutable int x;
	bool operator < (const odt &a) const {
		return l < a.l;
	}
};
set<odt> tr;
typedef set <odt> :: iterator IT;
IT split(int pos) {
	auto it = tr.lower_bound({pos, 0, 0});
	if (it != tr.end() && it->l == pos) return it;
	it--;
	int l = it->l, r = it->r, x = it->x;
	tr.erase(it);
	tr.insert({l, pos - 1, x});
	return tr.insert({pos, r, x}).first;
}
void assign(int l, int r, int x) {
	auto R = split(r + 1);
	auto L = split(l);
	tr.erase(L, R);
	tr.insert({l, r, x});
}
int query(int l, int r) {
	auto R = split(r + 1);
	auto L = split(l);
	int ans = 0;
	for (auto it = L; it != R; it++) {
		ans += it->x * (it->r - it->l + 1);
	}
	return ans;
}
void solve(int test_i) {
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int T = 1;
	cin >> T;
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}