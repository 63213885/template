int AndSum(int l, int r) {
	int ans = r, pos = 0;
	for(int i = 1; r > 0; i++) {
		if ((l & 1) ^ (r & 1)) pos = i;
		l >>= 1;
		r >>= 1;
	}
	ans >>= pos;
	ans <<= pos;
	return ans;
}