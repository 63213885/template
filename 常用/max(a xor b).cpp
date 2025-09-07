#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    ll a, b;
    while (T--) {
        cin >> a >> b;
        int count = 0;
        while ((a | ((ll)1 << count)) < b) {
            a |= ((ll)1 << count);
            count++;
        }
        ll x = 1;
        while (count--)
        {
            x |= ((ll)1 << (count + 1));
        }
        if (a != b)
            cout << x << endl;
        else cout << 0 << endl;
    }
}