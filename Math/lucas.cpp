int C(int a, int b) {
	if (a < b) return 0;
	int ans = 1;
	for (int i = a, j = 1; i >= b + 1; i--, j++) {
		ans = ans * i % p;
		ans = ans * qmi(j, p - 2, p) % p;
	}
	return ans;
}
int lucas(int a, int b, int p) {
	if (a < p && b < p) {
		return C(a, b, p);
	}
	return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}