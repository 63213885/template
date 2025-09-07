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

template <typename T, const int P>
struct single_hash {
	int n;
	std::vector<T> h, hi, p;
	single_hash(string s) : n(s.size() - 1), h(n + 1), hi(n + 2), p(n + 1) {
		p[0] = 1;
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] * P;
			h[i] = h[i - 1] * P + s[i];
		}
		for (int i = n; i >= 1; i--) {
			hi[i] = hi[i + 1] * P + s[i];
		}
	}
	T get(int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
	T geti(int l, int r) {
		return hi[l] - hi[r + 1] * p[r - l + 1];
	}
	bool ispalindrome(int l, int r) {
		return get(l, r) == geti(l, r);
	}
	bool same(int l1, int r1, int l2, int r2) {
		return get(l1, r1) == get(l2, r2);
	}
	T MergeFF(int l1, int r1, int l2, int r2) { // Forward and Forward
		return get(l1, r1) * p[r2 - l2 + 1] + get(l2, r2);
	}
	T MergeFR(int l1, int r1, int l2, int r2) { // Forward and reverse
		return get(l1, r1) * p[r2 - l2 + 1] + geti(l2, r2);
	}
	T MergeRF(int l1, int r1, int l2, int r2) { // reverse and Forward
		return geti(l1, r1) * p[r2 - l2 + 1] + get(l2, r2);
	}
	T MergeRR(int l1, int r1, int l2, int r2) { // reverse and reverse
		return geti(l1, r1) * p[r2 - l2 + 1] + geti(l2, r2);
	}
};
using SingleHash1 = single_hash<MInt<P>, 131>;
using SingleHash2 = single_hash<MInt<0>, 13331>;

struct DoubleHash : SingleHash1, SingleHash2 {
	using SingleHash1::single_hash;
	using SingleHash2::single_hash;
	
	DoubleHash(string s) : SingleHash1::single_hash(s), SingleHash2::single_hash(s) {}

	pair<int, int> get(int l, int r) {
		int h1 = SingleHash1::get(l, r).val();
		int h2 = SingleHash2::get(l, r).val();
		return pair<int, int> (h1, h2);
	}
	pair<int, int> geti(int l, int r) {
		int h1 = SingleHash1::geti(l, r).val();
		int h2 = SingleHash2::geti(l, r).val();
		return pair<int, int> (h1, h2);
	}
	bool ispalindrome(int l, int r) {
		return SingleHash1::ispalindrome(l, r) && SingleHash2::ispalindrome(l, r);
	}
	bool same(int l1, int r1, int l2, int r2) {
		return SingleHash1::same(l1, r1, l2, r2) && SingleHash2::same(l1, r1, l2, r2);
	}
	pair<int, int> MergeFF(int l1, int r1, int l2, int r2) { // Forward and Forward
		int h1 = SingleHash1::MergeFF(l1, r1, l2, r2).val();
		int h2 = SingleHash2::MergeFF(l1, r1, l2, r2).val();
		return pair<int, int> (h1, h2);
	}
	pair<int, int> MergeFR(int l1, int r1, int l2, int r2) { // Forward and reverse
		int h1 = SingleHash1::MergeFR(l1, r1, l2, r2).val();
		int h2 = SingleHash2::MergeFR(l1, r1, l2, r2).val();
		return pair<int, int> (h1, h2);
	}
	pair<int, int> MergeRF(int l1, int r1, int l2, int r2) { // reverse and Forward
		int h1 = SingleHash1::MergeRF(l1, r1, l2, r2).val();
		int h2 = SingleHash2::MergeRF(l1, r1, l2, r2).val();
		return pair<int, int> (h1, h2);
	}
	pair<int, int> MergeRR(int l1, int r1, int l2, int r2) { // reverse and reverse
		int h1 = SingleHash1::MergeRR(l1, r1, l2, r2).val();
		int h2 = SingleHash2::MergeRR(l1, r1, l2, r2).val();
		return pair<int, int> (h1, h2);
	}
};