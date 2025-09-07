namespace fastread {
	const int BUFLEN = 200000;
	char buf[BUFLEN], *p1, *p2;
	#define Fread fread(buf, 1, BUFLEN, stdin)
	#define getchar() (((p1 == p2) && (p2 = (p1 = buf) + Fread)), *p1++)
	template <typename T> void inline read(T &x) {
		int f = 1; x = 0; char c = getchar();
		while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
		while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
		x *= f;
	}
	template <typename T> void inline print(T x) {
		if (x < 0) putchar('-'), x = -x;
		if (x >= 10) print(x / 10); putchar(x % 10 + 48);
	}
	template <typename T> void inline print(T x,char c) {
		print(x); putchar(c);
	}
}
using namespace fastread;