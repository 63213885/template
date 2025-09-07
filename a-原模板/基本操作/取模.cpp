#include <bits/stdc++.h>

//#define int long long
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
constexpr bool multiple_test_cases = 0;
const int M;
// assume -M <= x < 2M
int norm(int x) {
	if (x < 0) {
		x += M;
	}
	if (x >= M) {
		x -= M;
	}
	return x;
}
template<typename T>
T qmi(T n, LL k) {
	T res = 1;
	while (k) {
		if (k & 1) res = res * n;
		n *= n;
		k /= 2;
	}
	return res;
}
struct Z {
	int x;
	Z(int x = 0) : x(norm(x)) {}
	Z(LL x) : x(norm(x % M)) {}
	int val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(M - x));
	}
	Z inv() const {
		assert(x != 0);
		return qmi(*this, M - 2);
	}
	Z &operator*=(const Z &rhs) {
		x = LL(x) * rhs.x % M;
		return *this;
	}
	Z &operator+=(const Z &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z &operator-=(const Z &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z &operator/=(const Z &rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res *= rhs;
		return res;
	}
	friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res += rhs;
		return res;
	}
	friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res -= rhs;
		return res;
	}
	friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res /= rhs;
		return res;
	}
	friend std::istream &operator>>(std::istream &is, Z &a) {
		LL v;
		is >> v;
		a = Z(v);
		return is;
	}
	friend std::ostream &operator<<(std::ostream &os, const Z &a) {
		return os << a.val();
	}
};
void solve(int test_i) {
	
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(3);
	int T = 1;
	if (multiple_test_cases) {
		cin >> T;
	}
	for (int test_i = 1; test_i <= T; test_i++) {
		solve(test_i);
	}
	return 0 ^ 0;
}