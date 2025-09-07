int OrSum(int l, int r) {
	if (l == r) return l;
	int pos = 63;
	while (!((l ^ r) & 1LL << pos)) --pos;
	while (~pos) l |= 1LL << pos--;
	return l;
}