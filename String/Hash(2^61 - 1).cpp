using ULL = unsigned long long;
const ULL M = (1ull << 61) - 1;
ULL add(ULL a, ULL b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}
ULL mul(ULL a, ULL b) {
	__uint128_t c = __uint128_t(a) * b;
	return add(c >> 61, c & M);
}