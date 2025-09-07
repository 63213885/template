template<typename T>
T power(T n, long long k) {
	T res = 1;
	while (k) {
		if (k & 1) res = res * n;
		n *= n;
		k /= 2;
	}
	return res;
}
template <const int M>
struct MLong {
	int x;
	int norm(int x) {
		if (x >= M) {
			x -= M;
		}
		if (x < 0) {
			x += M;
		}
		return x;
	}
	MLong(int _x = 0) : x(norm(_x % M)) {}
	int val() const {
		return x;
	}
	MLong operator -() const {
		return MLong(-x);
	}
	MLong inv() const {
		assert(x != 0);
		return power(*this, M - 2);
	}
	MLong &operator *=(const MLong &rhs) {
		x = norm((__int128)(x) * rhs.x % M);
		return *this;
	}
	MLong &operator +=(const MLong &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	MLong &operator -=(const MLong &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	MLong &operator /=(const MLong &rhs) {
		return *this *= rhs.inv();
	}
	bool operator < (const MLong &rhs) {
		return x < rhs.x;
	}
	bool operator == (const MLong &rhs) {
		return x == rhs.x;
	}
	bool operator != (const MLong &rhs) {
		return x != rhs.x;
	}
	friend MLong operator *(const MLong &lhs, const MLong &rhs) {
		MLong res = lhs;
		res *= rhs;
		return res;
	}
	friend MLong operator +(const MLong &lhs, const MLong &rhs) {
		MLong res = lhs;
		res += rhs;
		return res;
	}
	friend MLong operator -(const MLong &lhs, const MLong &rhs) {
		MLong res = lhs;
		res -= rhs;
		return res;
	}
	friend MLong operator /(const MLong &lhs, const MLong &rhs) {
		MLong res = lhs;
		res /= rhs;
		return res;
	}
	friend std::istream &operator >>(std::istream &is, MLong &a) {
		long long v;
		is >> v;
		a = MLong(v);
		return is;
	}
	friend std::ostream &operator <<(std::ostream &os, const MLong &a) {
		return os << a.val();
	}
};
using Z = MLong<(int)(998244353)>;