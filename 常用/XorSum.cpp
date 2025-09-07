int PreXorSum(int n) {
	int ans = 0;
	for (int i = n / 4 * 4; i <= n; i++) {
		ans ^= i;
	}
	return ans;
}
int XorSum(int l, int r) {
	return PreXorSum(r) ^ PreXorSum(l - 1);
}