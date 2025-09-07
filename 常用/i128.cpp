istream &operator>>(istream &is, __int128 &n) {
	n = 0;
	string s;
	cin >> s;
	for (auto c : s) {
		n = n * 10 + c - '0';
	}
	return is;
}
ostream &operator<<(ostream &os, __int128 n) {
	string s;
	while (n) {
		s += '0' + n % 10;
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return os << s;
}