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

struct matrix {
	Z x[2][2];
	friend matrix operator *(const matrix &lhs, const matrix &rhs) {
		matrix res = {0, 0, 0, 0};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					res.x[i][j] += lhs.x[i][k] * rhs.x[k][j];
				}
			}
		}
		return res;
	}
};

Z Fib(int n) {
	if (!n) return 0;
	matrix a = {0, 1, 1, 1}, res = {1, 0, 0, 1};
	int k = n - 1;
	while (k) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}
	return res.x[0][0] + res.x[1][0];
}