#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define range(x, l, r) x.begin() + l, x.begin() + r + 1

using namespace std;
using LL = long long;
using PII = pair<int, int>;
namespace Debug {
    template <typename U, typename T>
    void print_arg(const U &Arg, const T &arg) {
        cerr << Arg << " = " << arg;
    }
    template <typename T>
    void err(string Arg, const T &arg) {
        print_arg(Arg, arg); cerr << endl;
    }
    template <typename T, typename... Ts>
    void err(string Arg, const T &arg, const Ts &...args) {
        size_t pos = Arg.find(',');
        print_arg(Arg.substr(0, pos), arg); cerr << ",";
        err(Arg.substr(pos + 1), args...);
    }
    #define debug(args...) err(#args, ##args)
}
using namespace Debug;
/*<------------------------------------------------------------->*/
constexpr bool multiple_test_cases = 0;

void solve(int test_i) {
    
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T = 1;
    if (multiple_test_cases) {
        cin >> T;
    }
    for (int test_i = 1; test_i <= T; test_i++) {
        solve(test_i);
    }
    return 0 ^ 0;
}