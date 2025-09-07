namespace jzz2_0 {
	#define LL long long
	#define endl "\n"
	#define fi first
	#define se second
	#define inf 0x3f3f3f3f
	#define INF 0x3f3f3f3f3f3f3f3f
	#define all(x) x.begin(), x.end()
	#define all1(x) x.begin() + 1, x.end()
	#define range(x, l, r) x.begin() + l, x.begin() + r + 1
	template <typename U, typename T>
	void print_arg(const U &Arg, const T &arg) {
		std::cout << Arg << " = " << arg;
	}
	template <typename T>
	void err(std::string Arg, const T &arg) {
		print_arg(Arg, arg); std::cout << endl;
	}
	template <typename T, typename... Ts>
	void err(std::string Arg, const T &arg, const Ts &...args) {
		size_t pos = Arg.find(',');
		print_arg(Arg.substr(0, pos), arg); std::cout << ",";
		err(Arg.substr(pos + 1), args...);
	}
	#define debug(args...) err(#args, ##args)
}
using namespace jzz2_0;