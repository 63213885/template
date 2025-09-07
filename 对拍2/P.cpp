#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include <random>
#include<numeric>
#include<string>
#include<string.h>
#include<iterator>
#include<fstream>
#include<map>
#include<unordered_map>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<iomanip>
#include<bitset>

//#pragma gcc optimize(2)
//#pragma gcc optimize(3)

#define endl '\n'
#define int ll
#define pi acos(-1)
#define inf 0x3f3f3f3f
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int>PII;
typedef pair<ll, pair<ll, ll>>PIII;
const int N = 2e5 + 50, mod = 998244353, MOD = 1e9 + 7, base = 13331;

/*
注意到ai只有20，可以用状态压缩来表示选了哪些数

f[i][j]表示到第i个数，之前没有选取过j，且子序列的状态最长为f[i][j]
j=0表示尽量长就行，不管哪些数被选了

这里的长，重点在于二进制下的1要尽可能多

记录每个数上一次出现的位置k，从这个位置转移过来
f[i][j]=ops_max((f[i-1][j]),(f[k-1]|1<<a[i]));


8
1 2 3 3 2 1 3 3
4

10 
1 1 1 1 1 1 1 2 1 2

8
1 2 3 4 5 6 7 8

8
1 20 20 3 3 8 8 1

*/

int a[N], f[N][30], last[N];

int ops(int x)
{
    int cnt = 0;
    for (int i = 0; i <= 21; i++)
    {
        cnt += ((x >> i) & 1);
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (last[a[i]] != 0)
        {
            int j = last[a[i]];
            int num = (f[j - 1][a[i]] | (1LL << a[i]));
            int x = ops(num);
            //拿最新的去和其它所有位置做比较
            //谁更优用谁
            //但要注意新状态不能包含数字j
            for (int j = 0; j <= 21; j++)
            {
                if (!((num >> j) & 1) && ops(f[i - 1][j]) < x)
                {
                    f[i][j] = num;
                }
                else f[i][j] = f[i - 1][j];
            }
        }
        else
        {
            for (int j = 0; j <= 21; j++)
            {
                f[i][j] = f[i - 1][j];
            }
        }
        last[a[i]] = i;
    }

    cout << ops(f[n][0]) * 2 << endl;
}

signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}