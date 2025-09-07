template<class T>
constexpr T power(T a, LL b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
template<int P>
struct MInt {
	int x;
	constexpr MInt() : x{} {}
	constexpr MInt(LL x) : x{norm(x % getMod())} {}
	
	static int Mod;
	constexpr static int getMod() {
		if (P > 0) {
			return P;
		} else {
			return Mod;
		}
	}
	constexpr static void setMod(int Mod_) {
		Mod = Mod_;
	}
	constexpr int norm(int x) const {
		if (x < 0) {
			x += getMod();
		}
		if (x >= getMod()) {
			x -= getMod();
		}
		return x;
	}
	constexpr int val() const {
		return x;
	}
	explicit constexpr operator int() const {
		return x;
	}
	constexpr MInt operator-() const {
		MInt res;
		res.x = norm(getMod() - x);
		return res;
	}
	constexpr MInt inv() const {
		assert(x != 0);
		return power(*this, getMod() - 2);
	}
	constexpr MInt &operator*=(MInt rhs) & {
		x = 1LL * x * rhs.x % getMod();
		return *this;
	}
	constexpr MInt &operator+=(MInt rhs) & {
		x = norm(x + rhs.x);
		return *this;
	}
	constexpr MInt &operator-=(MInt rhs) & {
		x = norm(x - rhs.x);
		return *this;
	}
	constexpr MInt &operator/=(MInt rhs) & {
		return *this *= rhs.inv();
	}
	friend constexpr MInt operator*(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res *= rhs;
		return res;
	}
	friend constexpr MInt operator+(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res += rhs;
		return res;
	}
	friend constexpr MInt operator-(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res -= rhs;
		return res;
	}
	friend constexpr MInt operator/(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res /= rhs;
		return res;
	}
	friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
		LL v;
		is >> v;
		a = MInt(v);
		return is;
	}
	friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
		return os << a.val();
	}
	friend constexpr bool operator==(MInt lhs, MInt rhs) {
		return lhs.val() == rhs.val();
	}
	friend constexpr bool operator!=(MInt lhs, MInt rhs) {
		return lhs.val() != rhs.val();
	}
};

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;

namespace Combinatorics {
	int n;
	std::vector<Z> _fac = {1}, _inv = {1};
	void init(int m) {
		if (m <= n) return;
		_fac.resize(m + 1);
		_inv.resize(m + 1);
		for (int i = n + 1; i <= m; i++) {
			_fac[i] = _fac[i - 1] * i;
		}
		_inv[m] = _fac[m].inv();
		for (int i = m; i > n; i--) {
			_inv[i - 1] = _inv[i] * i;
		}
		n = m;
	}
	Z fac(int m) {
		if (m > n) init(2 * m);
		return _fac[m];
	}
	Z inv(int m) {
		if (m > n) init(2 * m);
		return _inv[m];
	}
	Z C(int a, int b) {
		if (a < b || b < 0) return Z(0);
		return fac(a) * inv(b) * inv(a - b);
	}
	Z A(int a, int b) {
		if (a < b || b < 0) return Z(0);
		return fac(a) * inv(a - b);
	}
	Z H(int a, int b) {
		return C(a + b - 1, b);
	}
}
using namespace Combinatorics;