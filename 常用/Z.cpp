int M;
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
T qmi(T n, long long k) {
	T res = 1;
	while (k) {
		if (k & 1) res = res * n;
		n *= n;
		k /= 2;
	}
	return res;
}
struct ModInt {
	int x;
	ModInt(int x = 0) : x(norm(x % M)) {}
	int val() const {
		return x;
	}
	ModInt operator -() const {
		return ModInt(norm(M - x));
	}
	ModInt inv() const {
		assert(x != 0);
		return qmi(*this, M - 2);
	}
	ModInt &operator *=(const ModInt &rhs) {
		x = (long long)(x) * rhs.x % M;
		return *this;
	}
	ModInt &operator +=(const ModInt &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	ModInt &operator -=(const ModInt &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	ModInt &operator /=(const ModInt &rhs) {
		return *this *= rhs.inv();
	}
	bool operator < (const ModInt &rhs) {
		return x < rhs.x;
	}
	bool operator == (const ModInt &rhs) {
		return x == rhs.x;
	}
	bool operator != (const ModInt &rhs) {
		return x != rhs.x;
	}
	friend ModInt operator *(const ModInt &lhs, const ModInt &rhs) {
		ModInt res = lhs;
		res *= rhs;
		return res;
	}
	friend ModInt operator +(const ModInt &lhs, const ModInt &rhs) {
		ModInt res = lhs;
		res += rhs;
		return res;
	}
	friend ModInt operator -(const ModInt &lhs, const ModInt &rhs) {
		ModInt res = lhs;
		res -= rhs;
		return res;
	}
	friend ModInt operator /(const ModInt &lhs, const ModInt &rhs) {
		ModInt res = lhs;
		res /= rhs;
		return res;
	}
	friend std::istream &operator >>(std::istream &is, ModInt &a) {
		long long v;
		is >> v;
		a = ModInt(v);
		return is;
	}
	friend std::ostream &operator <<(std::ostream &os, const ModInt &a) {
		return os << a.val();
	}
};
using Z = ModInt;