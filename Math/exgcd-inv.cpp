int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int inv(int n, int M) {
	// n * x = 1 (mod M) -> n * x + M * y = 1
	int x, y;
	exgcd(n, M, x, y);
	x = (x % M + M) % M;
	return x;
}