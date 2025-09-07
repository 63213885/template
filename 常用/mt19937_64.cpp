mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	int M = r - l + 1, x = rng();
	return l + (x % M + M) % M;
}
int rand_int(int l, int r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<int>(l, r)(gen);
}