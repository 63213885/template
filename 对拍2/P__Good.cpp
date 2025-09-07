#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    constexpr int num = 20;
    array<vector<int>, num> pos;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        --a;
        pos[a].push_back(i);
    }
    constexpr int up = (1 << num);
    vector<int> dp(up, n);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < up; ++i) {
        for (int j = 0; j < num; ++j) {
            if ((i >> j) & 1) {
                int la = i ^ (1 << j);
                auto it = lower_bound(pos[j].begin(), pos[j].end(), dp[la]);
                if (it != pos[j].end() && next(it) != pos[j].end()) {
                    dp[i] = min(dp[i], *next(it));
                    ans = max(ans, __builtin_popcount(i));
                }
            }
        }
    }
    cout << ans * 2 << '\n';
 
    return 0;
}