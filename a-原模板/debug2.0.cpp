namespace Debug {
	template <typename T>
	void print_arg(string_view Arg,const T &arg) {
		cerr << Arg << " = " << arg;
	}
	template <typename T>
	void dbg(string_view Arg, const T &arg) {
		print_arg(Arg, arg); cerr << endl;
	}
	template <typename T, typename... Ts>
	void dbg(string_view Args, const T &arg, const Ts&... args) {
		size_t pos = Args.find(',');
		print_arg(Args.substr(0, pos), arg); cerr << ",";
		dbg(Args.substr(pos + 1), args...);
	}
	#define debug(args...) dbg(#args, ##args)
}
using namespace Debug;